/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:19:38 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/07 16:29:28 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	stack_init(t_stack **stack)
{
	*stack = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!stack)
		return (ERROR);
	(*stack)->size = 0;
	(*stack)->top = NULL;
	(*stack)->bot = NULL;
	return (SUCCES);
}
