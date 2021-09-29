/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:45:26 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/29 12:07:08 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*pstr;

	i = 0;
	pstr = (unsigned char *)s;
	while (i < n)
	{
		pstr[i] = 0;
		i++;
	}
	s = pstr;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*b;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	size *= count;
	b = (void *)malloc(size);
	if (b)
		ft_bzero(b, size);
	return (b);
}

long	ft_atol(const char *str)
{
	long			num;
	int				i;
	long			sign;

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
	}
	return ((long)(sign * num));
}
