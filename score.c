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

static void reverse(char *str_nbr, int length, char *str)
{
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        temp = str_nbr[start];
        str_nbr[start] = str_nbr[end];
        str_nbr[end] = temp;
        start++;
        end--;
    }
    my_strcat(str, str_nbr);
}

static void int_in_string(int num, char *str_nbr, int *i, int isNegative)
{
    if (num == 0) {
        str_nbr[*i] = '0';
        *i = *i + 1;
    }
    while (num != 0) {
        str_nbr[*i] = num % 10 + '0';
        *i = *i + 1;
        num = num / 10;
    }
    if (isNegative) {
        str_nbr[*i] = '-';
        *i = *i + 1;
    }
}

void int_to_string(int num, char *str)
{
    int i = 0;
    int isNegative = 0;
    char *str_nbr;
    int temp;
    int cpt = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }
    temp = num;
    while (temp != 0) {
        temp /= 10;
        cpt++;
    }
    str_nbr = malloc((cpt + isNegative + 1) * sizeof(char));
    int_in_string(num, str_nbr, &i, isNegative);
    str_nbr[i] = '\0';
    reverse(str_nbr, i, str);
    free(str_nbr);
}

void draw_score_text(game_s *game)
{
    char *text = my_strdup(game->score->text_init);

    int_to_string(game->pts, text);
    sfText_setString(game->score->text, text);
    if (!my_strcmp(game->phase, "game") ||
        !my_strcmp(game->phase, "end") ||
        !my_strcmp(game->phase, "classement"))
        sfRenderWindow_drawText(game->window, game->score->text, NULL);
    free(text);
}

void draw_best_score(game_s *game)
{
    char *text = my_strdup(game->best->text_init);

    int_to_string(game->bestscore, text);
    sfText_setString(game->best->text, text);
    if (!my_strcmp(game->phase, "classement"))
        sfRenderWindow_drawText(game->window, game->best->text, NULL);
    free(text);
}

void draw_precision(game_s *game)
{
    char *text = my_strdup(game->text_precision->text_init);

    if (game->tirs == 0)
        game->precision_value = 0;
    else
        game->precision_value = (float)game->hits / (float)game->tirs * 100;
    int_to_string((int)game->precision_value, text);
    my_strcat(text, " %");
    sfText_setString(game->text_precision->text, text);
    if (!my_strcmp(game->phase, "classement"))
        sfRenderWindow_drawText(game->window, game->text_precision->text,
        NULL);
    free(text);
}
