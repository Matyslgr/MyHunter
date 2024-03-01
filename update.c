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

static void check_ghostparty(linked_list *ghostparty)
{
    ghostparty->has_clock->time = sfClock_getElapsedTime(ghostparty\
    ->has_clock->clock);
    ghostparty->has_clock->seconds = ghostparty->has_clock\
    ->time.microseconds / 1000000.0;
    if (ghostparty->has_clock->seconds > 3.0) {
        ghostparty->etat = 0;
        sfClock_restart(ghostparty->has_clock->clock);
    }
}

static void check_crow_clock(linked_list **list_elem, game_s *game)
{
    linked_list *crow = get_elem(*list_elem, "crow");

    game->crow_clock->time = sfClock_getElapsedTime(game->crow_clock->clock);
    game->crow_clock->seconds = game->crow_clock->time.microseconds /
    1000000.0;
    if (game->crow_clock->seconds > 10 && crow->etat == 0) {
        crow->etat = 1;
    }
}

static void elem_with_clock(linked_list *current, game_s *game)
{
    if (current->has_clock != NULL) {
        if (my_strcmp(current->info->name, "ghostparty") == 0)
            check_ghostparty(current);
        else
            move_rect(current, game);
    }
}

static void draw_cursor(game_s *game)
{
    game->cursor->pos.x = sfMouse_getPositionRenderWindow(game->window).x - 75;
    game->cursor->pos.y = sfMouse_getPositionRenderWindow(game->window).y - 75;
    sfSprite_setPosition(game->cursor->sprite, game->cursor->pos);
    sfRenderWindow_drawSprite(game->window, game->cursor->sprite, NULL);
}

void update_window(game_s *game, linked_list **list_elem)
{
    linked_list *current = *list_elem;

    sfRenderWindow_clear(game->window, sfBlack);
    display_background(game);
    if (!my_strcmp(game->phase, "game") || !my_strcmp(game->phase, "end"))
        check_crow_clock(list_elem, game);
    while (current != NULL) {
        if (current->etat == 1) {
            elem_with_clock(current, game);
            sfRenderWindow_drawSprite(game->window, current->sprite, NULL);
        }
        current = current->next;
    }
    draw_score_text(game);
    draw_best_score(game);
    draw_precision(game);
    draw_cursor(game);
    sfRenderWindow_display(game->window);
}
