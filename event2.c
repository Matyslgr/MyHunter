/*
** EPITECH PROJECT, 2023
** projetc
** File description:
** my_hunter
*/

#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "includes/struct.h"
#include "includes/my.h"

sfSprite *get_objet(linked_list *listElem, char *name)
{
    linked_list *current = listElem;

    while (current->next != NULL && my_strcmp(current->info->name, name)) {
        current = current->next;
    }
    return current->sprite;
}

void event_phase_start(linked_list **list_elem, game_s *game)
{
    sfSprite *sprite_play = get_objet(*list_elem, "play");
    sfFloatRect play_bounds = sfSprite_getGlobalBounds(sprite_play);

    if (sfFloatRect_contains(&play_bounds, game->event.mouseButton.x,
        game->event.mouseButton.y)) {
        sfClock_restart(game->crow_clock->clock);
        game->phase = "game";
    }
    sprite_play = get_objet(*list_elem, "difficulty");
    play_bounds = sfSprite_getGlobalBounds(sprite_play);
    if (sfFloatRect_contains(&play_bounds, game->event.mouseButton.x,
        game->event.mouseButton.y)) {
        game->phase = "set_difficult";
    }
}

static void ghost1_is_hit(linked_list **list_elem, game_s *game)
{
    linked_list *ghost = get_elem(*list_elem, "ghost");
    linked_list *smoke = get_elem(*list_elem, "smoke");

    smoke->info->pos = ghost->info->pos;
    smoke->etat = 1;
    smoke->has_clock->rect.left = 0;
    smoke->has_clock->rect.top = 0;
    ghost->info->pos.x = -249;
    ghost->info->y_origin = rand() % 800;
    if (my_strcmp(game->phase, "end") == 0) {
        ghost->info->velocity += game->offset_velocity;
    }
    sfSprite_setPosition(smoke->sprite, smoke->info->pos);
}

static void ghost2_is_hit(linked_list **list_elem, game_s *game)
{
    linked_list *ghost = get_elem(*list_elem, "ghost2");
    linked_list *smoke = get_elem(*list_elem, "smoke2");

    smoke->info->pos = ghost->info->pos;
    smoke->etat = 1;
    smoke->has_clock->rect.left = 0;
    smoke->has_clock->rect.top = 0;
    ghost->info->pos.x = 2000;
    ghost->info->y_origin = rand() % 800;
    if (my_strcmp(game->phase, "end") == 0) {
        ghost->info->velocity += game->offset_velocity;
    }
    sfSprite_setPosition(smoke->sprite, smoke->info->pos);
}

static void check_clic_ghost1(linked_list **list_elem, game_s *game)
{
    sfSprite *sprite_play = get_objet(*list_elem, "ghost");
    sfFloatRect play_bounds = sfSprite_getGlobalBounds(sprite_play);

    if (sfFloatRect_contains(&play_bounds, game->event.mouseButton.x,
        game->event.mouseButton.y)) {
        ghost1_is_hit(list_elem, game);
        game->pts += 1;
        game->hits += 1;
        game->is_hit = true;
    }
}

static void check_clic_ghost2(linked_list **list_elem, game_s *game)
{
    sfSprite *sprite_play = get_objet(*list_elem, "ghost2");
    sfFloatRect play_bounds = sfSprite_getGlobalBounds(sprite_play);

    if (sfFloatRect_contains(&play_bounds, game->event.mouseButton.x,
        game->event.mouseButton.y)) {
        ghost2_is_hit(list_elem, game);
        game->pts += 1;
        game->hits += 1;
        game->is_hit = true;
    }
}

static void ghost3or4_is_hit(linked_list **list_elem, game_s *game,
    char *name, char *smoke_name)
{
    linked_list *ghost = get_elem(*list_elem, name);
    linked_list *smoke = get_elem(*list_elem, smoke_name);

    smoke->info->pos = ghost->info->pos;
    smoke->etat = 1;
    smoke->has_clock->rect.left = 0;
    smoke->has_clock->rect.top = 0;
    ghost->info->y_origin = rand() % 800;
    ghost->etat = 0;
    if (my_strcmp(ghost->info->name, "ghost3") == 0) {
        active_elem(list_elem, "ghost4");
        ghost->info->pos.x = -250;
    } else {
        active_elem(list_elem, "ghost3");
        ghost->info->pos.x = 1980;
    }
    if (my_strcmp(game->phase, "end") == 0) {
        ghost->info->velocity += game->offset_velocity;
    }
    sfSprite_setPosition(smoke->sprite, smoke->info->pos);
}

static void check_clic_ghost3or4(linked_list **list_elem, game_s *game,
    char *name, char *smoke_name)
{
    sfSprite *sprite_play = get_objet(*list_elem, name);
    sfFloatRect play_bounds = sfSprite_getGlobalBounds(sprite_play);

    if (sfFloatRect_contains(&play_bounds, game->event.mouseButton.x,
        game->event.mouseButton.y)) {
        ghost3or4_is_hit(list_elem, game, name, smoke_name);
        game->pts += 1;
        game->hits += 1;
        game->is_hit = true;
    }
}

void event_phase_game_end(linked_list **list_elem, game_s *game)
{
    game->is_hit = false;
    check_clic_ghost1(list_elem, game);
    check_clic_ghost2(list_elem, game);
    check_clic_ghost3or4(list_elem, game, "ghost3", "smoke3");
    check_clic_ghost3or4(list_elem, game, "ghost4", "smoke4");
    if (my_strcmp(game->phase, "game") == 0 && game->pts >= 10) {
        game->phase = "end";
        active_elem(list_elem, "ghost3");
        active_elem(list_elem, "ghost4");
        if (is_activate(*list_elem, "ghostparty") == 0) {
            active_elem(list_elem, "ghostparty");
            active_clock(list_elem, "ghostparty");
        }
    }
    if (!game->is_hit && game->pts > 0) {
        game->pts -= 1;
    }
}
