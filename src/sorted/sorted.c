/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:56:09 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/14 18:08:57 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	is_stack_sorted(t_stack *stack, int type)
{
	t_node	*node;

	node = stack->top;
	if (type == AS)
	{
		while (node && node->next)
		{
			if (node->data > node->next->data)
				return (FALSE);
			node = node->next;
		}
	}
	if (type == DES)
	{
		while (node && node->prev)
		{
			if (node->data > node->prev->data)
				return (FALSE);
			node = node->prev;
		}
	}
	return (TRUE);
}

int	small_stack_size(t_stack *stack)
{
	if (stack->size == 2)
	{
		return (TRUE);
	}
	if (stack->size == 3)
		return (TRUE);
	if (stack->size == 4)
		return (TRUE);
	if (stack->size == 5)
		return (TRUE);
	return (FALSE);
}

int sort_stack()
{
	return (SUCCESS);
}