/*
** EPITECH PROJECT, 2023
** Day08
** File description:
** my_strdup
*/
#include <stdlib.h>
#include <stdio.h>
#include "includes/my.h"

char *my_strdup(char const *src)
{
    int len_src = my_strlen(src);
    char *str = malloc(sizeof(char) * (len_src + 1));

    my_strcpy(str, src);
    return str;
}
