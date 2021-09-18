/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:53:15 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/18 13:15:46 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_stack(int argc, char *argv[])
{
    int need_to_free;
    
    argv++;
    need_to_free = 0;
    if (argc < 2)
        error_message();
    if (argc == 2)
    {
        argv = ft_split(*argv, ' ');
        need_to_free++;
    }
    return (need_to_free);
}