/*
** EPITECH PROJECT, 2023
** Day06
** File description:
** Task06
*/
#include <string.h>
#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
        i++;
    }
    if (s1[i] == '\0' && s2[i] != '\0')
        return -s2[i];
    else
        return s1[i] - s2[i];
}
