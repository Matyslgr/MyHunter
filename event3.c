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

static void desactive_all_difficult(linked_list **list_elem)
{
    desactive_elem(list_elem, "select_difficult");
    desactive_elem(list_elem, "hard");
    desactive_elem(list_elem, "medium");
    desactive_elem(list_elem, "easy");
}

static void check_easy(linked_list **list_elem, game_s *game)
{
    sfSprite *sprite_play = get_objet(*list_elem, "easy");
    sfFloatRect play_bounds = sfSprite_getGlobalBounds(sprite_play);

    if (sfFloatRect_contains(&play_bounds, game->event.mouseButton.x,
        game->event.mouseButton.y)) {
        game->life = 3;
        game->offset_velocity = 0.5;
        game->phase = "start";
        desactive_all_difficult(list_elem);
    }
}

void event_phase_set_difficult(linked_list **list_elem, game_s *game)
{
    sfSprite *sprite_play = get_objet(*list_elem, "hard");
    sfFloatRect play_bounds = sfSprite_getGlobalBounds(sprite_play);

    if (sfFloatRect_contains(&play_bounds, game->event.mouseButton.x,
        game->event.mouseButton.y)) {
        game->life = 1;
        game->offset_velocity = 1.2;
        game->phase = "start";
        desactive_all_difficult(list_elem);
    }
    sprite_play = get_objet(*list_elem, "medium");
    play_bounds = sfSprite_getGlobalBounds(sprite_play);
    if (sfFloatRect_contains(&play_bounds, game->event.mouseButton.x,
        game->event.mouseButton.y)) {
        game->life = 2;
        game->offset_velocity = 0.8;
        game->phase = "start";
        desactive_all_difficult(list_elem);
    }
    check_easy(list_elem, game);
}
