/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:56:09 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/19 10:26:36 by dacortes         ###   ########.fr       */
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

int	the_size_is_three(t_stack *a)
{
	int	index;

	index = 1;
	while (index != a->top->index)
		reverse_rotate(a, REV_ROTATE_A);
	if (is_stack_sorted(a, AS))
		return (SUCCESS);
	swap(a, SWAP_A);
	rotate(a, ROTATE_A);
	return (SUCCESS);
}

int	the_size_is_five(t_stack *a, t_stack *b)
{
	int	index;

	index = 5;
	while (index != a->top->index)
	{
		reverse_rotate(a, REV_ROTATE_A);
		if (a->top->index == 4)
			push(a, b, PUSH_B);
	}
	push(a, b, PUSH_B);
	index--;
	if (b->size != 2)
	{
		while (index != a->top->index)
			reverse_rotate(a, REV_ROTATE_A);
	}
	push(a, b, PUSH_B);
	the_size_is_three(a);
	push(b, a, PUSH_B);
	rotate(a, ROTATE_A);
	push(b, a, PUSH_B);
	rotate(a, ROTATE_A);
	return (SUCCESS);
}

int	small_stack_size(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (is_stack_sorted(a, DES))
			swap(a, SWAP_A);
		return (TRUE);
	}
	if (a->size == 3)
	{
		the_size_is_three(a);
		return (TRUE);
	}
	if (a->size == 4)
	{
		the_size_is_four(a , b);
		return (TRUE);
	}
	if (a->size == 5)
	{
		the_size_is_five(a, b);
		return (TRUE);
	}
	return (FALSE);
}

int sort_stack()
{
	return (SUCCESS);
}