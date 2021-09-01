#include "../includes/push_swap.h"

void print_string(char **argv, int stack_size)
{
    int i;

    i = 0;
    while (i < stack_size)
    {
        ft_putstr(argv[i]);
        i++;
    }
}