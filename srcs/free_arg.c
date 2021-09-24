/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:41:58 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/24 13:34:58 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_argv(char *argv[])
{
	int		i;

	i = 0;
	if (argv)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}

void	free_stack(t_stack *stack)
{
	free(stack->a->arr);
	free(stack->b->arr);
	free(stack->t->og);
	free(stack->a);
	free(stack->b);
	free(stack->t);
}
