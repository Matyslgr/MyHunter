/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Day09
*/
#pragma once
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "struct.h"

int my_getnbr(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strdup(char const *src);
char *my_strcat(char *dest, char const *src);
int is_activate(linked_list *list_elem, char *name);
void desactive_elem(linked_list **listElem, char *name);
void active_elem(linked_list **listElem, char *name);
void update_window(game_s *game, linked_list **list_elem);
void analyse_events(linked_list **list_elem, game_s *game);
void add_ghost(linked_list **listElem, char *name);
void add_play(linked_list **list_elem);
linked_list *get_elem(linked_list *list_elem, char *name);
void add_smoke(linked_list **list_elem, char *name);
void add_ghost2(linked_list **list_elem, char *name);
void add_first_back(game_s *game);
void add_second_back(game_s *game);
void add_third_back(game_s *game);
void display_background(game_s *game);
void add_elem(linked_list **list_elem, sfSprite *new_sprite, info_s *info,
    clock_s *new_clock);
void add_fourth_back(game_s *game);
void add_ghostparty(linked_list **list_elem);
void active_clock(linked_list **list_elem, char *name);
clock_s *init_myclock_ghost(int rect_left, int max_value, int offset);
void draw_score_text(game_s *game);
void move_rect(linked_list *elem, game_s *game);
game_s *init_game(void);
void destroy_list(linked_list *listElem);
void add_all(linked_list **list_elem);
void add_heart(linked_list **list_elem, char *name, int pos_x);
void add_my_hunter(linked_list **list_elem);
void add_gameover(linked_list **list_elem);
void add_difficulty(linked_list **list_elem);
void add_selct_difficult(linked_list **list_elem);
void add_hard(linked_list **list_elem);
void add_medium(linked_list **list_elem);
void add_easy(linked_list **list_elem);
void add_boo(linked_list **list_elem);
void add_crow(linked_list **list_elem);
void draw_best_score(game_s *game);
int get_bestscore(char *filepath);
int my_getnbr(char const *str);
void int_to_string(int num, char *str);
void new_bestscore(char *filepath, game_s *game);
void add_save(linked_list **list_elem);
void add_retry(linked_list **list_elem);
void add_stats(linked_list **list_elem);
void add_back(linked_list **list_elem);
void is_boo(linked_list *elem);
void is_crow(linked_list *elem);
void set_crow(linked_list *list_elem, game_s *game);
void set_ghost1(linked_list *list_elem, game_s *game, char *name);
void set_ghost2(linked_list *list_elem, game_s *game, char *name);
void restart_all(linked_list **list_elem, game_s *game);
void event_phase_set_difficult(linked_list **list_elem, game_s *game);
void event_phase_game_end(linked_list **list_elem, game_s *game);
sfSprite *get_objet(linked_list *listElem, char *name);
void event_phase_start(linked_list **list_elem, game_s *game);
void destroy_cursor(cursor_s *cursor);
void destroy_game(game_s *game);
void draw_precision(game_s *game);
