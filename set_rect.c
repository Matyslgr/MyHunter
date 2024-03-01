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

static void is_ghost1_rect(linked_list *elem)
{
    if (elem->has_clock->seconds > 0.15) {
        if (elem->has_clock->rect.left + elem->has_clock->offset
            < elem->has_clock->max_value) {
            elem->has_clock->rect.left += elem->has_clock->offset;
        } else {
            elem->has_clock->rect.left = 0;
        }
        sfClock_restart(elem->has_clock->clock);
    }
}

static void is_ghost2_rect(linked_list *elem)
{
    if (elem->has_clock->seconds > 0.15) {
        if (elem->has_clock->rect.left - elem->has_clock->offset > 0) {
            elem->has_clock->rect.left -= elem->has_clock->offset;
        } else {
            elem->has_clock->rect.left = 1050;
        }
        sfClock_restart(elem->has_clock->clock);
    }
}

static void timeout_smoke(linked_list *elem)
{
    if (elem->has_clock->rect.left + elem->has_clock->offset
        < elem->has_clock->max_value) {
        elem->has_clock->rect.left += elem->has_clock->offset;
    } else if (elem->has_clock->rect.top + elem->has_clock->offset
        < elem->has_clock->max_value) {
        elem->has_clock->rect.top += elem->has_clock->offset;
        elem->has_clock->rect.left = 0;
    } else {
        elem->etat = 0;
    }
}

static void is_smoke(linked_list *elem)
{
    if (elem->has_clock->seconds > 0.06) {
        timeout_smoke(elem);
        sfClock_restart(elem->has_clock->clock);
    }
}

static void lost_life(linked_list *elem)
{
    if (elem->has_clock->rect.left + elem->has_clock->offset <
        elem->has_clock->max_value) {
        elem->has_clock->rect.left += elem->has_clock->offset;
    } else {
        elem->etat = 0;
    }
    sfClock_restart(elem->has_clock->clock);
}

static void is_heart(linked_list *elem, game_s *game)
{
    if (elem->has_clock->seconds > 0.05) {
        if ((game->life < 3 && my_strcmp(elem->info->name, "heart3") == 0) ||
            (game->life < 2 && my_strcmp(elem->info->name, "heart2") == 0) ||
            (game->life < 1 && my_strcmp(elem->info->name, "heart1") == 0) ) {
            lost_life(elem);
        }
    }
}

static void move_rect3(linked_list *elem, game_s *game)
{
    if (!my_strcmp(elem->info->name, "heart1") ||
        !my_strcmp(elem->info->name, "heart2") ||
        !my_strcmp(elem->info->name, "heart3"))
        is_heart(elem, game);
    else if (my_strcmp(elem->info->name, "boo") == 0)
        is_boo(elem);
}

static void move_rect2(linked_list *elem, game_s *game)
{
    if (my_strcmp(elem->info->name, "smoke") == 0 ||
        my_strcmp(elem->info->name, "smoke2") == 0 ||
        my_strcmp(elem->info->name, "smoke3") == 0 ||
        my_strcmp(elem->info->name, "smoke4") == 0)
        is_smoke(elem);
    else if (my_strcmp(elem->info->name, "crow") == 0)
        is_crow(elem);
    else
        move_rect3(elem, game);
}

void move_rect(linked_list *elem, game_s *game)
{
    elem->has_clock->time = sfClock_getElapsedTime(elem->has_clock->clock);
    elem->has_clock->seconds = elem->has_clock->time.microseconds / 1000000.0;
    if (my_strcmp(elem->info->name, "ghost") == 0 ||
        my_strcmp(elem->info->name, "ghost3") == 0)
        is_ghost1_rect(elem);
    else if (my_strcmp(elem->info->name, "ghost2") == 0 ||
        my_strcmp(elem->info->name, "ghost4") == 0)
        is_ghost2_rect(elem);
    else
        move_rect2(elem, game);
    sfSprite_setTextureRect(elem->sprite, elem->has_clock->rect);
}
