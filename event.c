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


static void close_window(game_s *game)
{
    sfRenderWindow_close(game->window);
}

static void event_phase_gameover(linked_list **list_elem, game_s *game)
{
    sfSprite *sprite_play = get_objet(*list_elem, "stats");
    sfFloatRect play_bounds = sfSprite_getGlobalBounds(sprite_play);

    if (sfFloatRect_contains(&play_bounds, game->event.mouseButton.x,
        game->event.mouseButton.y)) {
        game->phase = "classement";
    }
    sprite_play = get_objet(*list_elem, "retry");
    play_bounds = sfSprite_getGlobalBounds(sprite_play);
    if (sfFloatRect_contains(&play_bounds, game->event.mouseButton.x,
        game->event.mouseButton.y)) {
        restart_all(list_elem, game);
    }
}

static void active_gameover(linked_list **list_elem)
{
    active_elem(list_elem, "gameover");
    active_elem(list_elem, "boo");
    active_elem(list_elem, "retry");
    active_elem(list_elem, "stats");
}

static void desactive_classement(linked_list **list_elem)
{
    desactive_elem(list_elem, "save");
    desactive_elem(list_elem, "back");
}

static void event_phase_classement(linked_list **list_elem, game_s *game)
{
    sfSprite *sprite_play = get_objet(*list_elem, "save");
    sfFloatRect play_bounds = sfSprite_getGlobalBounds(sprite_play);

    if (sfFloatRect_contains(&play_bounds, game->event.mouseButton.x,
        game->event.mouseButton.y)) {
        new_bestscore("bestscore.txt", game);
    }
    sprite_play = get_objet(*list_elem, "back");
    play_bounds = sfSprite_getGlobalBounds(sprite_play);
    if (sfFloatRect_contains(&play_bounds, game->event.mouseButton.x,
        game->event.mouseButton.y)) {
        desactive_classement(list_elem);
        active_gameover(list_elem);
        game->phase = "gameover";
    }
}

static void button_pressed(linked_list **list_elem, game_s *game)
{
    if (my_strcmp(game->phase, "start") == 0)
        event_phase_start(list_elem, game);
    if (my_strcmp(game->phase, "set_difficult") == 0)
        event_phase_set_difficult(list_elem, game);
    if (my_strcmp(game->phase, "game") == 0 ||
        my_strcmp(game->phase, "end") == 0) {
        event_phase_game_end(list_elem, game);
        if (is_activate(*list_elem, "play") == 0) {
            sfSound_play(game->music->tir);
            game->tirs += 1;
        }
    }
    if (!my_strcmp(game->phase, "gameover"))
        event_phase_gameover(list_elem, game);
    if (my_strcmp(game->phase, "classement") == 0)
        event_phase_classement(list_elem, game);
}

void analyse_events(linked_list **list_elem, game_s *game)
{
    if (game->event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape))
        close_window(game);
    else if (game->event.type == sfEvtMouseButtonPressed) {
        button_pressed(list_elem, game);
    }
}
