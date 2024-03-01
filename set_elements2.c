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
#include <math.h>

static void game_over(linked_list *list_elem, game_s *game)
{
    if (is_activate(list_elem, "ghost") == 1) {
        game->phase = "gameover";
        desactive_elem(&list_elem, "ghost");
        desactive_elem(&list_elem, "ghost2");
        desactive_elem(&list_elem, "ghost3");
        desactive_elem(&list_elem, "ghost4");
        desactive_elem(&list_elem, "crow");
    }
    if (is_activate(list_elem, "gameover") == 0) {
        active_elem(&list_elem, "gameover");
        active_elem(&list_elem, "boo");
        active_elem(&list_elem, "retry");
        active_elem(&list_elem, "stats");
    }
}

static void check_is_alive(linked_list *list_elem, game_s *game)
{
    if (game->life <= 0) {
        sfSound_play(game->music->boo);
        game_over(list_elem, game);
    }
}

void set_ghost1(linked_list *list_elem, game_s *game, char *name)
{
    linked_list *ghost = get_elem(list_elem, name);
    sfColor ghostColor = sfSprite_getColor(ghost->sprite);
    float y_offset = 100.0 * sin(ghost->info->pos.x / 100.0);

    if (ghost->info->pos.x < 1920) {
        ghost->info->pos.x += ghost->info->velocity;
    } else {
        game->life -= 1;
        check_is_alive(list_elem, game);
        ghost->info->pos.x = -100;
    }
    ghost->info->pos.y = ghost->info->y_origin + y_offset;
    sfSprite_setPosition(ghost->sprite, ghost->info->pos);
    ghostColor.a = (sfUint8)(128 + 128 * sin(ghost->info->pos.x / 140.0));
    sfSprite_setColor(ghost->sprite, ghostColor);
}

void set_ghost2(linked_list *list_elem, game_s *game, char *name)
{
    linked_list *ghost = get_elem(list_elem, name);
    sfColor ghostColor = sfSprite_getColor(ghost->sprite);
    float y_offset = 100.0 * sin(ghost->info->pos.x / 100.0);

    if (ghost->info->pos.x > -200) {
        ghost->info->pos.x -= ghost->info->velocity;
    } else {
        game->life -= 1;
        check_is_alive(list_elem, game);
        ghost->info->pos.x = 2000;
    }
    ghost->info->pos.y = ghost->info->y_origin + y_offset;
    sfSprite_setPosition(ghost->sprite, ghost->info->pos);
    ghostColor.a = (sfUint8)(128 + 128 * sin(ghost->info->pos.x / 140.0));
    sfSprite_setColor(ghost->sprite, ghostColor);
}

void set_crow(linked_list *list_elem, game_s *game)
{
    linked_list *crow = get_elem(list_elem, "crow");
    float y_offset = 50.0 * sin(crow->info->pos.x / 100.0);

    if (crow->info->pos.x < 2000) {
        crow->info->pos.x += crow->info->velocity;
    } else {
        crow->info->pos.x = -150;
        crow->etat = 0;
        sfClock_restart(game->crow_clock->clock);
    }
    crow->info->pos.y = crow->info->y_origin + y_offset;
    sfSprite_setPosition(crow->sprite, crow->info->pos);
}
