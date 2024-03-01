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

static void clock_boo(linked_list *elem)
{
    if (elem->has_clock->rect.left + elem->has_clock->offset
        < elem->has_clock->max_value) {
        elem->has_clock->rect.left += elem->has_clock->offset;
    } else if (elem->has_clock->rect.top + elem->has_clock->down
        <= elem->has_clock->down_max) {
        elem->has_clock->rect.top += elem->has_clock->down;
        elem->has_clock->rect.left = 0;
    } else {
        elem->has_clock->rect.top = 0;
        elem->has_clock->rect.left = 0;
    }
}

void is_boo(linked_list *elem)
{
    if (elem->has_clock->seconds > 0.014) {
        clock_boo(elem);
        sfClock_restart(elem->has_clock->clock);
    }
}

void is_crow(linked_list *elem)
{
    if (elem->has_clock->seconds > 0.035) {
        if (elem->has_clock->rect.left + elem->has_clock->offset
            < elem->has_clock->max_value) {
            elem->has_clock->rect.left += elem->has_clock->offset;
        } else {
            elem->has_clock->rect.top = 0;
            elem->has_clock->rect.left = 0;
        }
        sfClock_restart(elem->has_clock->clock);
    }
}
