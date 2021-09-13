/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:48:11 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/07 13:50:22 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}

int	ft_atoi(const char *str)
{
	long			num;
	int				i;
	int				sign;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
	}
	return ((long)(sign * num));
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9' || c == '-'));
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void       ft_putnbr(int nb)
{
    unsigned int nombre;

    if (nb < 0)
    {
        ft_putchar('-');
        nombre = -nb;
    }
    else
        nombre = nb;
    if (nombre > 9)
    {
        ft_putnbr(nombre / 10);
        nombre %= 10;
    }
    ft_putchar(nombre + '0');
}