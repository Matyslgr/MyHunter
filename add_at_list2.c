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

void add_ghost2(linked_list **list_elem, char *name)
{
    sfTexture *text = sfTexture_createFromFile("images/ghost_reversed.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();
    clock_s *my_clock = init_myclock_ghost(1050, 1050, 148);

    info->name = name;
    info->pos = (sfVector2f){2000, 0};
    info->velocity = 3.0;
    info->y_origin = rand() % 800;
    while (info->y_origin < 200)
        info->y_origin = rand() % 800;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, my_clock);
}

void add_smoke(linked_list **list_elem, char *name)
{
    sfTexture *text = sfTexture_createFromFile("images/smoke.png",
    NULL);
    sfSprite *sprite = sfSprite_create();
    info_s *info = malloc(sizeof(info_s));
    clock_s *my_clock = init_myclock_ghost(0, 450, 150);

    info->name = name;
    info->pos = (sfVector2f){0, 0};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    add_elem(list_elem, sprite, info, my_clock);
}

static clock_s *init_myclock_heart(void)
{
    clock_s *my_clock = malloc(sizeof(clock_s));
    sfTime time = {0};
    float seconds = 0.0;
    sfClock *clock = sfClock_create();
    sfIntRect rect = {0, 0, 175, 135};

    my_clock->clock = clock;
    my_clock->time = time;
    my_clock->seconds = seconds;
    my_clock->rect = rect;
    my_clock->max_value = 1250;
    my_clock->offset = 175;
    return (my_clock);
}

void add_heart(linked_list **list_elem, char *name, int pos_x)
{
    sfTexture *text = sfTexture_createFromFile("images/heart.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();
    clock_s *my_clock = init_myclock_heart();

    info->name = name;
    info->pos = (sfVector2f){pos_x, 0};
    info->velocity = 2.0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, my_clock);
}

void add_my_hunter(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/my_hunter.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();

    info->name = "my_hunter";
    info->pos = (sfVector2f){550, 150};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, NULL);
}

void add_gameover(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/gameover.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();

    info->name = "gameover";
    info->pos = (sfVector2f){600, 100};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, NULL);
}
