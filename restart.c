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

static void restart_ghost(linked_list **list_elem)
{
    linked_list *ghost = get_elem(*list_elem, "ghost");
    linked_list *ghost2 = get_elem(*list_elem, "ghost2");
    linked_list *ghost3 = get_elem(*list_elem, "ghost3");
    linked_list *ghost4 = get_elem(*list_elem, "ghost4");

    ghost->info->pos.x = -249;
    ghost->info->y_origin = rand() % 800;
    ghost->info->velocity = 2.0;
    ghost2->info->pos.x = 2000;
    ghost2->info->velocity = 3.0;
    ghost2->info->y_origin = rand() % 800;
    ghost3->info->pos.x = -249;
    ghost3->info->velocity = 2.0;
    ghost3->info->y_origin = rand() % 800;
    ghost4->info->pos.x = 2000;
    ghost4->info->velocity = 3.0;
    ghost4->info->y_origin = rand() % 800;
}

static void restart_score(game_s *game)
{
    sfFont* font = sfFont_createFromFile("font/Clone Age.ttf");
    char *text_init = "Score : ";
    sfVector2f pos = {25, 25};

    sfText_setFont(game->score->text, font);
    sfText_setOutlineThickness(game->score->text, (float) 3.0);
    sfText_setCharacterSize(game->score->text, 40);
    sfText_setPosition(game->score->text, pos);
    game->score->text_init = text_init;
    game->score->font = font;
    game->score->pos = pos;
    game->score->color = sfWhite;
}

void restart_all(linked_list **list_elem, game_s *game)
{
    linked_list *crow = get_elem(*list_elem, "crow");

    restart_ghost(list_elem);
    restart_score(game);
    get_elem(*list_elem, "heart1")->has_clock->rect.left = 0;
    get_elem(*list_elem, "heart2")->has_clock->rect.left = 0;
    get_elem(*list_elem, "heart3")->has_clock->rect.left = 0;
    game->phase = "start";
    game->pts = 0;
    game->life = 3;
    game->hits = 0;
    game->tirs = 0;
    crow->info->pos.x = -249;
    desactive_elem(list_elem, "gameover");
    desactive_elem(list_elem, "boo");
    desactive_elem(list_elem, "retry");
    desactive_elem(list_elem, "stats");
    active_elem(list_elem, "play");
    active_elem(list_elem, "my_hunter");
    active_elem(list_elem, "difficulty");
}
