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

void add_first_back(game_s *game)
{
    sfTexture* texture = sfTexture_createFromFile("background/jour.jpg", NULL);
    sfSprite* sprite = sfSprite_create();
    info_s *info = malloc(sizeof(info_s));

    info->name = "back1";
    info->pos = (sfVector2f){0, 0};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, texture, sfTrue);
    add_elem(&game->back_list, sprite, info, NULL);
}

void add_second_back(game_s *game)
{
    sfTexture* texture = sfTexture_createFromFile("background/lune.jpg", NULL);
    sfSprite* sprite = sfSprite_create();
    info_s *info = malloc(sizeof(info_s));

    info->name = "back2";
    info->pos = (sfVector2f){0, 0};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, texture, sfTrue);
    add_elem(&game->back_list, sprite, info, NULL);
}

void add_third_back(game_s *game)
{
    sfTexture* texture = sfTexture_createFromFile("background/ghost.jpg",
    NULL);
    sfSprite* sprite = sfSprite_create();
    info_s *info = malloc(sizeof(info_s));

    info->name = "back3";
    info->pos = (sfVector2f){0, 0};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, texture, sfTrue);
    add_elem(&game->back_list, sprite, info, NULL);
}

void add_fourth_back(game_s *game)
{
    sfTexture* texture = sfTexture_createFromFile("background/nuit.jpg", NULL);
    sfSprite* sprite = sfSprite_create();
    info_s *info = malloc(sizeof(info_s));

    info->name = "back4";
    info->pos = (sfVector2f){0, 0};
    info->velocity = 0;
    info->y_origin = 0;
    sfSprite_setTexture(sprite, texture, sfTrue);
    add_elem(&game->back_list, sprite, info, NULL);
}

static linked_list *check_activation_background(game_s *game, char *name_act,
    char *name_desa)
{
    linked_list *background;

    if (is_activate(game->back_list, name_desa) == 1)
        desactive_elem(&game->back_list, name_desa);
    if (is_activate(game->back_list, name_act) == 0) {
        active_elem(&game->back_list, name_act);
    }
    background = get_elem(game->back_list, name_act);
    return (background);
}

static linked_list *display_background2(game_s *game)
{
    linked_list *background;

    if (!my_strcmp(game->phase, "end")) {
        background = check_activation_background(game, "back3", "back2");
    } else if (!my_strcmp(game->phase, "gameover") ||
        !my_strcmp(game->phase, "classement")) {
        background = check_activation_background(game, "back4", "back3");
    }
    return (background);
}

void display_background(game_s *game)
{
    linked_list *background;

    if (my_strcmp(game->phase, "start") == 0 ||
        my_strcmp(game->phase, "set_difficult") == 0) {
        if (is_activate(game->back_list, "back1") == 0)
            active_elem(&game->back_list, "back1");
        background = get_elem(game->back_list, "back1");
    } else if (my_strcmp(game->phase, "game") == 0) {
        background = check_activation_background(game, "back2", "back1");
    } else {
        background = display_background2(game);
    }
    sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
}
