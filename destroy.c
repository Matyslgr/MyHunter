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

void destroy_game(game_s *game)
{
    sfText_destroy(game->score->text);
    sfFont_destroy(game->score->font);
    free(game->score);
    sfText_destroy(game->best->text);
    sfFont_destroy(game->best->font);
    free(game->best);
    sfMusic_stop(game->music->music);
    sfSound_stop(game->music->tir);
    sfSound_stop(game->music->boo);
    sfSoundBuffer_destroy(game->music->buffer_boo);
    sfSoundBuffer_destroy(game->music->buffer);
    sfMusic_destroy(game->music->music);
    sfSound_destroy(game->music->tir);
    sfSound_destroy(game->music->boo);
    free(game->music);
}

void destroy_cursor(cursor_s *cursor)
{
    sfTexture_destroy(cursor->text);
    sfSprite_destroy(cursor->sprite);
    free(cursor);
}

void destroy_list(linked_list *listElem)
{
    linked_list *current = listElem;
    const sfTexture *temp_texture;
    sfTexture *texture;

    while (current != NULL) {
        temp_texture = sfSprite_getTexture(current->sprite);
        texture = (sfTexture *)temp_texture;
        sfSprite_destroy(current->sprite);
        sfTexture_destroy(texture);
        if (current->has_clock != NULL)
            sfClock_destroy(current->has_clock->clock);
        free(current->has_clock);
        free(current->info);
        current = current->next;
    }
}
