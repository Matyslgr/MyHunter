/*
** EPITECH PROJECT, 2023
** Day04
** File description:
** Task05
*/
#include <stdio.h>
#include <limits.h>

static void num_find(char const *str, int i, long int *num)
{
    int y = i + 1;

    while (str[y] >= 48 && str[y] <= 57) {
        *num = (*num * 10) + (str[y] - '0');
        y++;
    }
}

static void if_not_int(long int *num)
{
    long long unsigned int nb = *num;

    if (*num < -2147483648 || *num > INT_MAX || nb == ULLONG_MAX) {
        *num = 0;
    }
}

static int nb_chain(char const *str, int y, int type)
{
    long int num;

    for (int i = y; str[i] != 0; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = str[i] - '0';
            num_find(str, i, &num);
            num *= type;
            if_not_int(&num);
            return num;
        }
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int type = 1;
    int y = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '-')
            type = type * (-1);
    }
    if (str[y] == '+' || str[y] == '-' || (str[y] <= 57 && str[y] >= 48)) {
        while (str[y] == '-' || str[y] == '+')
            y++;
        return nb_chain(str, y, type);
    }
    return 0;
}
