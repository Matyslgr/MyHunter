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

void active_clock(linked_list **list_elem, char *name)
{
    linked_list *current = *list_elem;

    while (current->next != NULL &&
        my_strcmp(current->info->name, name) != 0) {
        current = current->next;
    }
    current->has_clock->clock = sfClock_create();
}

void active_elem(linked_list **listElem, char *name)
{
    linked_list *current = *listElem;

    while (current->next != NULL &&
        my_strcmp(current->info->name, name) != 0) {
        current = current->next;
    }
    current->etat = 1;
}

void desactive_elem(linked_list **listElem, char *name)
{
    linked_list *current = *listElem;

    while (current->next != NULL &&
        my_strcmp(current->info->name, name) != 0) {
        current = current->next;
    }
    current->etat = 0;
}

int is_activate(linked_list *list_elem, char *name)
{
    linked_list *current = list_elem;

    while (current != NULL && my_strcmp(current->info->name, name) != 0) {
        current = current->next;
    }
    if (current->etat == 1)
        return (1);
    else
        return (0);
}

linked_list *get_elem(linked_list *list_elem, char *name)
{
    linked_list *current = list_elem;

    while (current->next != NULL && my_strcmp(current->info->name, name)) {
        current = current->next;
    }
    return current;
}
