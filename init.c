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

static text_s *init_score(void)
{
    text_s *score = malloc(sizeof(text_s));
    sfFont* font = sfFont_createFromFile("font/Clone Age.ttf");
    sfText* text = sfText_create();
    char *text_init = "Score : ";
    sfVector2f pos = {25, 25};

    sfText_setFont(text, font);
    sfText_setOutlineThickness(text, (float) 3.0);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, pos);
    score->text = text;
    score->text_init = text_init;
    score->font = font;
    score->pos = pos;
    score->color = sfWhite;
    return (score);
}

static text_s *init_best(void)
{
    text_s *best = malloc(sizeof(text_s));
    sfFont* font = sfFont_createFromFile("font/Say Comic.ttf");
    sfText* text = sfText_create();
    char *text_init = "Best Score : ";
    sfVector2f pos = {350, 100};

    sfText_setFont(text, font);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, (float) 5.0);
    sfText_setCharacterSize(text, 150);
    sfText_setPosition(text, pos);
    best->text = text;
    best->text_init = text_init;
    best->font = font;
    best->pos = pos;
    best->color = sfWhite;
    return (best);
}

static clock_s *create_crow_clock(void)
{
    clock_s *my_clock = malloc(sizeof(clock_s));
    sfTime time = {0};
    float seconds = 0.0;
    sfClock *clock = sfClock_create();

    my_clock->time = time;
    my_clock->seconds = seconds;
    my_clock->clock = clock;
    return my_clock;
}

static void add_all_background(game_s *game)
{
    add_first_back(game);
    add_second_back(game);
    add_third_back(game);
    add_fourth_back(game);
}

static cursor_s *init_cursor(void)
{
    cursor_s *cursor = malloc(sizeof(cursor_s));

    cursor->text = sfTexture_createFromFile("images/cursor.png", NULL);
    cursor->sprite = sfSprite_create();
    cursor->pos.x = 0;
    cursor->pos.y = 0;
    sfSprite_setScale(cursor->sprite, (sfVector2f){0.35, 0.35});
    sfSprite_setTexture(cursor->sprite, cursor->text, sfTrue);
    return (cursor);
}

static music_s *init_music(void)
{
    music_s *music = malloc(sizeof(music_s));

    music->music = sfMusic_createFromFile("Sound/music.ogg");
    music->tir = sfSound_create();
    music->buffer = sfSoundBuffer_createFromFile("Sound/tir.ogg");
    sfSound_setBuffer(music->tir, music->buffer);
    sfMusic_setLoop(music->music, sfTrue);
    sfMusic_setVolume(music->music, 50);
    sfSound_setVolume(music->tir, 50);
    music->buffer_boo = sfSoundBuffer_createFromFile("Sound/soundboo.ogg");
    music->boo = sfSound_create();
    sfSound_setBuffer(music->boo, music->buffer_boo);
    sfSound_setVolume(music->boo, 50);
    sfMusic_play(music->music);
    return (music);
}

static text_s *init_precision(void)
{
    text_s *text_precision = malloc(sizeof(text_s));
    sfFont* font = sfFont_createFromFile("font/Say Comic.ttf");
    sfText* text = sfText_create();
    char *text_init = "Accuracy : ";
    sfVector2f pos = {300, 500};

    sfText_setFont(text, font);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, (float) 5.0);
    sfText_setCharacterSize(text, 150);
    sfText_setPosition(text, pos);
    text_precision->text = text;
    text_precision->text_init = text_init;
    text_precision->font = font;
    text_precision->pos = pos;
    text_precision->color = sfWhite;
    return (text_precision);
}

static game_s *init_game2(game_s *game)
{
    game->phase = "start";
    game->life = 3;
    game->offset_velocity = 0.5;
    game->cursor = init_cursor();
    game->crow_clock = create_crow_clock();
    game->bestscore = get_bestscore("bestscore.txt");
    game->music = init_music();
    game->tirs = 0;
    game->hits = 0;
    return game;
}

game_s *init_game(void)
{
    game_s *game = malloc(sizeof(game_s));
    text_s *score = init_score();
    text_s *best = init_best();
    text_s *text_precision = init_precision();

    game->mode.width = 1920;
    game->mode.height = 1080;
    game->mode.bitsPerPixel = 32;
    game->window = sfRenderWindow_create(game->mode, "My Hunter",
        sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    game->score = score;
    game->best = best;
    game->text_precision = text_precision;
    game->pts = 0;
    game->precision_value = 0;
    init_game2(game);
    add_all_background(game);
    return (game);
}
