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

static void add_all2(linked_list **list_elem)
{
    add_heart(list_elem, "heart3", 1490);
    add_gameover(list_elem);
    add_boo(list_elem);
    add_save(list_elem);
    add_back(list_elem);
    add_retry(list_elem);
    add_stats(list_elem);
}

void add_all(linked_list **list_elem)
{
    add_play(list_elem);
    add_my_hunter(list_elem);
    add_difficulty(list_elem);
    add_selct_difficult(list_elem);
    add_hard(list_elem);
    add_medium(list_elem);
    add_easy(list_elem);
    add_ghostparty(list_elem);
    add_crow(list_elem);
    add_ghost(list_elem, "ghost");
    add_ghost2(list_elem, "ghost2");
    add_ghost(list_elem, "ghost3");
    add_ghost2(list_elem, "ghost4");
    add_smoke(list_elem, "smoke");
    add_smoke(list_elem, "smoke2");
    add_smoke(list_elem, "smoke3");
    add_smoke(list_elem, "smoke4");
    add_heart(list_elem, "heart1", 1750);
    add_heart(list_elem, "heart2", 1620);
    add_all2(list_elem);
}
