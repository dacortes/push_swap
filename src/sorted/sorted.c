/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:56:09 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/24 15:27:26 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	is_stack_sorted(t_stack *stack, int type)
{
	t_node	*node;

	if (type == AS)
	{
		node = stack->top;
		while (node && node->next)
		{
			if (node->data > node->next->data)
				return (FALSE);
			node = node->next;
		}
	}
	if (type == DES)
	{
		node = stack->bot;
		while (node && node->prev)
		{
			if (node->data > node->prev->data)
				return (FALSE);
			node = node->prev;
		}
	}
	return (TRUE);
}

int	small_stack_size(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (is_stack_sorted(a, DES))
			swap(a, STACK_A);
		return (TRUE);
	}
	else if (a->size == 3)
	{
		the_size_is_three(a);
		return (TRUE);
	}
	else if (a->size == 4)
	{
		the_size_is_four(a, b);
		return (TRUE);
	}
	else if (a->size == 5)
	{
		the_size_is_five(a, b);
		return (TRUE);
	}
	return (FALSE);
}
