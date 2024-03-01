/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** my_strcat
*/
#include <stdio.h>
#include <string.h>
#include "includes/my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}
/*
void main(void)
{
    char dest[12] = "Bonjour";
    char dest_true[12] = "Bonjour";
    char src[] = "World";
    printf("%s\n", my_strcat(dest, src));
    printf("%s\n", strcat(dest_true, src));
}

*/
