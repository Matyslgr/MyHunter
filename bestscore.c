/*
** EPITECH PROJECT, 2023
** projetc
** File description:
** my_hunter
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "includes/struct.h"
#include "includes/my.h"
#include <string.h>

static int get_lennbr(int nb)
{
    int cpt = 0;

    while (nb > 1) {
        nb /= 10;
        cpt++;
    }
    return cpt + 1;
}

void new_bestscore(char *filepath, game_s *game)
{
    int fd = open(filepath, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    char *str;
    int lennbr = get_lennbr(game->pts);

    if (fd != -1) {
        if (game->bestscore < game->pts) {
            str = malloc(sizeof(char) * (lennbr + 1));
            str[0] = '\0';
            int_to_string(game->pts, str);
            write(fd, str, my_strlen(str));
            write(fd, "\n", 1);
            game->bestscore = game->pts;
            close(fd);
        } else {
            my_putstr("Votre score est trop bas...\n");
        }
    } else {
        my_putstr("Erreur lors de l'ouverture du fichier");
    }
}

static int check_bestscore(char *str)
{
    int temp;
    int bestscore = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        temp = my_getnbr(&str[i]);
        if (temp > bestscore)
            bestscore = temp;
    }
    return bestscore;
}

int get_bestscore(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *str = NULL;
    int bestscore;

    if (fd != -1) {
        str = malloc(sizeof(char) * 30000);
        read(fd, str, 30000);
        bestscore = check_bestscore(str);
    } else
        my_putstr("Erreur lors de l'ouverture du fichier");
    close(fd);
    return bestscore;
}
