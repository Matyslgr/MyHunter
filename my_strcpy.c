/*
** EPITECH PROJECT, 2023
** Day06
** File description:
** Task01
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i + 1] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    dest[i + 1] = '\0';
    return dest;
}
