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
#include <math.h>

static void show_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_hunter\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     A game where you have to kill ghost\n");
    my_putstr("     You have 3 lives\n");
    my_putstr("     You can choose the difficulty\n");
    my_putstr("     You can see the stats\n");
    my_putstr("     You can retry\n");
    my_putstr("INPUT\n");
    my_putstr("     Mouse\n");
}

static void phase_start(linked_list *list_elem, game_s *game)
{
    if (is_activate(list_elem, "play") == 0) {
        active_elem(&list_elem, "my_hunter");
        active_elem(&list_elem, "play");
        active_elem(&list_elem, "difficulty");
    }
    game = game;
}

static void modify_pos_ghost(linked_list *list_elem, game_s *game)
{
    set_ghost1(list_elem, game, "ghost");
    set_ghost2(list_elem, game, "ghost2");
    if (my_strcmp(game->phase, "end") == 0 &&
        is_activate(list_elem, "ghost3") == 1)
        set_ghost1(list_elem, game, "ghost3");
    else if (my_strcmp(game->phase, "end") == 0 &&
        is_activate(list_elem, "ghost4") == 1)
        set_ghost2(list_elem, game, "ghost4");
}

static void phase_game_end(linked_list *list_elem, game_s *game)
{
    if (is_activate(list_elem, "ghost") == 0) {
        active_elem(&list_elem, "heart1");
        active_elem(&list_elem, "heart2");
        active_elem(&list_elem, "heart3");
        active_elem(&list_elem, "ghost");
        active_elem(&list_elem, "ghost2");
        if (my_strcmp(game->phase, "end") == 0) {
            active_elem(&list_elem, "ghost3");
            active_elem(&list_elem, "ghost4");
        }
        if (is_activate(list_elem, "play") == 1) {
            desactive_elem(&list_elem, "play");
            desactive_elem(&list_elem, "my_hunter");
            desactive_elem(&list_elem, "difficulty");
        }
    }
    if (is_activate(list_elem, "crow") == 1)
        set_crow(list_elem, game);
    modify_pos_ghost(list_elem, game);
}

static void phase_set_difficult(linked_list *list_elem)
{
    if (is_activate(list_elem, "play") == 1) {
        desactive_elem(&list_elem, "my_hunter");
        desactive_elem(&list_elem, "play");
        desactive_elem(&list_elem, "difficulty");
        active_elem(&list_elem, "select_difficult");
        active_elem(&list_elem, "hard");
        active_elem(&list_elem, "medium");
        active_elem(&list_elem, "easy");
    }
}

static void phase_classement(linked_list *list_elem, game_s *game)
{
    sfFont* font = sfFont_createFromFile("font/Say Comic.ttf");

    if (is_activate(list_elem, "gameover") == 1) {
        desactive_elem(&list_elem, "gameover");
        desactive_elem(&list_elem, "boo");
        desactive_elem(&list_elem, "retry");
        desactive_elem(&list_elem, "stats");
    }
    if (is_activate(list_elem, "save") == 0) {
        active_elem(&list_elem, "save");
        active_elem(&list_elem, "back");
        game->score->text_init = "Your Score : ";
        sfText_setOutlineThickness(game->score->text, (float) 5.0);
        sfText_setCharacterSize(game->score->text, 150);
        game->score->font = font;
        sfText_setFont(game->score->text, font);
        game->score->pos = (sfVector2f){340, 300};
        sfText_setPosition(game->score->text, game->score->pos);
    }
}

static void get_phase2(linked_list *list_elem, game_s *game)
{
    if (my_strcmp(game->phase, "game") == 0 ||
        my_strcmp(game->phase, "end") == 0) {
        phase_game_end(list_elem, game);
    } else if (!my_strcmp(game->phase, "classement")) {
        phase_classement(list_elem, game);
    }
}

static void get_phase(linked_list *list_elem, game_s *game)
{
    if (my_strcmp(game->phase, "start") == 0) {
        phase_start(list_elem, game);
    } else if (my_strcmp(game->phase, "set_difficult") == 0) {
        phase_set_difficult(list_elem);
    } else {
        get_phase2(list_elem, game);
    }
}

static int my_hunter(void)
{
    game_s *game = init_game();
    linked_list *list_elem = NULL;

    srand((unsigned int)time(NULL));
    add_all(&list_elem);
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event)) {
            analyse_events(&list_elem, game);
        }
        get_phase(list_elem, game);
        update_window(game, &list_elem);
    }
    destroy_game(game);
    destroy_list(list_elem);
    destroy_list(game->back_list);
    destroy_cursor(game->cursor);
    sfRenderWindow_destroy(game->window);
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        show_help();
        return (0);
    }
    if (ac != 1) {
        my_putstr("Error : too many arguments\n");
        return (84);
    }
    return (my_hunter());
}
