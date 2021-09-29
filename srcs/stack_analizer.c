/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_analizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:30:11 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/29 12:06:34 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size_calculator(int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc > 2)
		i = argc - 1;
	while (argv[i])
		i++;
	return (i);
}

int	if_digit_duplicate(char *argv[], int stack_size)
{
	int		i;
	int		j;
	long	stack_array;

	i = 0;
	while (i < stack_size)
	{
		j = i + 1;
		stack_array = ft_atol(argv[i]);
		if (stack_array < (long)INT_MIN || stack_array > (long)INT_MAX)
			error_message();
		while (j < stack_size)
		{
			if (stack_array == ft_atol(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	if_array_is_digit(char **argv, int stack_size)
{
	int		i;
	int		j;

	i = 0;
	while (i < stack_size)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			if (argv[i][j] == '-' && argv[i][j + 1] == '-')
				error_message();
			j++;
		}
		i++;
	}
	return (0);
}

void	if_valid_args(char *argv[], int stack_size)
{
	if (if_digit_duplicate(argv, stack_size)
		|| if_array_is_digit(argv, stack_size))
		error_message();
}
