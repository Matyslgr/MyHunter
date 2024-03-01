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

void add_difficulty(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/difficulty.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();

    info->name = "difficulty";
    info->pos = (sfVector2f){1100, 880};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, NULL);
}

void add_selct_difficult(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/select_difficult.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();

    info->name = "select_difficult";
    info->pos = (sfVector2f){320, 175};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, NULL);
}

void add_hard(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/hard.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();

    info->name = "hard";
    info->pos = (sfVector2f){780, 480};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, NULL);
}

void add_medium(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/medium.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();

    info->name = "medium";
    info->pos = (sfVector2f){700, 650};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, NULL);
}

void add_easy(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/easy.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();

    info->name = "easy";
    info->pos = (sfVector2f){780, 820};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, NULL);
}
