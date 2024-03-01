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

void add_elem(linked_list **list_elem, sfSprite *new_sprite, info_s *info,
    clock_s *new_clock)
{
    linked_list *new = (linked_list *)malloc(sizeof(linked_list));

    new->sprite = new_sprite;
    new->etat = 0;
    new->next = *list_elem;
    new->info = info;
    new->has_clock = new_clock;
    *list_elem = new;
}

void add_play(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/play.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();

    info->name = "play";
    info->pos = (sfVector2f){100, 800};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, NULL);
}

clock_s *init_myclock_ghost(int rect_left, int max_value, int offset)
{
    clock_s *my_clock = malloc(sizeof(clock_s));
    sfTime time = {0};
    float seconds = 0.0;
    sfClock *clock = sfClock_create();
    sfIntRect rect = {rect_left, 0, 150, 150};

    my_clock->clock = clock;
    my_clock->time = time;
    my_clock->seconds = seconds;
    my_clock->rect = rect;
    my_clock->max_value = max_value;
    my_clock->offset = offset;
    return (my_clock);
}

void add_ghostparty(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/ghostparty.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();
    clock_s *my_clock = init_myclock_ghost(0, 0, 0);

    info->name = "ghostparty";
    info->pos = (sfVector2f){400, 750};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, my_clock);
}

void add_ghost(linked_list **listElem, char *name)
{
    sfTexture *text = sfTexture_createFromFile("images/ghost.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();
    clock_s *my_clock = init_myclock_ghost(0, 1192, 149);

    info->name = name;
    info->pos = (sfVector2f){-160, 0};
    info->velocity = 2.0;
    info->y_origin = rand() % 800;
    while (info->y_origin < 200)
        info->y_origin = rand() % 800;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(listElem, sprite, info, my_clock);
}
