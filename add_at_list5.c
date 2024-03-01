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

void add_stats(linked_list **list_elem)
{
    sfTexture *text = sfTexture_createFromFile("images/stats.png",
    NULL);
    info_s *info = malloc(sizeof(info_s));
    sfSprite *sprite = sfSprite_create();

    info->name = "stats";
    info->pos = (sfVector2f){1300, 640};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setPosition(sprite, info->pos);
    add_elem(list_elem, sprite, info, NULL);
}
