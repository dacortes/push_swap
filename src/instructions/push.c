/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:12:45 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/07 19:39:44 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	push_num(t_stack *stack, int num)
{
	t_node *new_node;

	new_node = (t_node *)ft_calloc(sizeof(t_node), 1);
	if (!new_node)
		return (ERROR);
	new_node->data = num;
	new_node->next = NULL;
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bot = new_node;
	}
	else
	{
		new_node->next = stack->top;
		stack->top = new_node;
	}
	stack->size++;
	return (SUCCES);
}