/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:56:09 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/17 10:03:27 by dacortes         ###   ########.fr       */
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

int	small_stack_size(t_stack *a, t_stack *b)
{
	t_aux	tmp;

	(void)b;
	tmp.num = 1;
	tmp.if_possible = TRUE;
	if (a->size == 2)
	{
		if (is_stack_sorted(a, DES) == TRUE)
			swap(a, SWAP_A);
		return (TRUE);
	}
	if (a->size == 3)
	{
		swap(a, SWAP_A);
		reverse_rotate(a, REV_ROTATE_A);
		return (TRUE);
	}
	if (a->size == 4)
		return (TRUE);
	if (a->size == 5)
		return (TRUE);
	return (FALSE);
}

int sort_stack()
{
	return (SUCCESS);
}