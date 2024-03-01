/*
** EPITECH PROJECT, 2023
** objets
** File description:
** struct
*/
#pragma once
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct text_t {
    sfText *text;
    char *text_init;
    sfFont *font;
    sfVector2f pos;
    sfColor color;
} text_s;

typedef struct clock_t {
    sfClock *clock;
    sfTime time;
    float seconds;
    sfIntRect rect;
    int max_value;
    int offset;
    int down_max;
    int down;
} clock_s;

typedef struct info_t {
    char *name;
    float velocity;
    int y_origin;
    sfVector2f pos;
} info_s;

typedef struct linked_list {
    sfSprite *sprite;
    int etat;
    info_s *info;
    clock_s *has_clock;

    struct linked_list *next;
} linked_list;

typedef struct cursor_t {
    sfSprite *sprite;
    sfTexture *text;
    sfVector2f pos;
} cursor_s;

typedef struct music_t {
    sfMusic *music;
    sfSound *tir;
    sfSound *boo;
    sfSoundBuffer *buffer;
    sfSoundBuffer *buffer_boo;
} music_s;

typedef struct game_t {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
    linked_list *back_list;
    text_s *score;
    text_s *best;
    text_s *text_precision;
    int precision_value;
    int bestscore;
    int pts;
    char *phase;
    int life;
    float offset_velocity;
    int tirs;
    int hits;
    bool is_hit;
    cursor_s *cursor;
    clock_s *crow_clock;
    music_s *music;
} game_s;
