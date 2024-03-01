/*
** EPITECH PROJECT, 2023
** Day04
** File description:
** Task03
*/

int my_strlen(char const *str)
{
    int len = 0;

    for (int i = 0 ; str[i] != '\0' ; i++) {
        len++;
    }
    return len;
}
