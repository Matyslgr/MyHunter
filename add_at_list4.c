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

static clock_s *init_myclock_boo(void)
{
    clock_s *my_clock = malloc(sizeof(clock_s));
    sfTime time = {0};
    float seconds = 0.0;
    sfClock *clock = sfClock_create();
    sfIntRect rect = {0, 0, 550, 485};

    my_clock->clock = clock;
    my_clock->time = time;
    my_clock->seconds = seconds;
    my_clock->rect = rect;
    my_clock->max_value = 553 * 20;
    my_clock->down_max = 485 * 2;
    my_clock->offset = 553;
    my_clock->down = 485;
    return (my_clock);
}

void add_boo(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/boo.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();
    clock_s *my_clock = init_myclock_boo();

    info->name = "boo";
    info->pos = (sfVector2f){80, 400};
    info->velocity = 1.0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1.4, 1.4});
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, my_clock);
}

static clock_s *init_myclock_crow(void)
{
    clock_s *my_clock = malloc(sizeof(clock_s));
    sfTime time = {0};
    float seconds = 0.0;
    sfClock *clock = sfClock_create();
    sfIntRect rect = {0, 0, 206, 218};

    my_clock->clock = clock;
    my_clock->time = time;
    my_clock->seconds = seconds;
    my_clock->rect = rect;
    my_clock->max_value = 207 * 25;
    my_clock->offset = 207;
    return (my_clock);
}

void add_crow(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/crow.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();
    clock_s *my_clock = init_myclock_crow();

    info->name = "crow";
    info->pos = (sfVector2f){-300, 0};
    info->velocity = 10.0;
    info->y_origin = rand() % 200;
    while (info->y_origin < 100)
        info->y_origin = rand() % 200;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, my_clock);
}

void add_save(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/save.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();

    info->name = "save";
    info->pos = (sfVector2f){1250, 800};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, NULL);
}

void add_back(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/back.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();

    info->name = "back";
    info->pos = (sfVector2f){300, 800};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, NULL);
}

void add_retry(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/retry.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();

    info->name = "retry";
    info->pos = (sfVector2f){1300, 850};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, NULL);
}
