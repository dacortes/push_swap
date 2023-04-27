/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:17:52 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/27 11:29:44 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	find_bot(t_stack *stack)
{
	t_node	*node;
	int		pos;

	pos = 1;
	node = stack->top;
	while (node)
	{
		node = node->next;
		if (node && node->index == stack->size)
			break ;
		pos++;
	}
	return (pos);
}

static void	number_of_chunks(t_aux *tmp, t_stack *a, t_stack *b)
{
	tmp->chunks = a->size / 25;
	while (a->size)
	{
		while (b->size != tmp->range_end && a->size != 0)
		{
			if (a->top->index >= tmp->range_ini
				&& a->top->index <= tmp->range_end)
			{
				push(a, b, STACK_B);
				if (b->size > 2 && b->top->index
					<= ((tmp->range_end - tmp->range_ini) / 2) + tmp->range_ini)
					rotate(b, STACK_B);
				tmp->num--;
			}
			reverse_rotate(a, STACK_A);
		}
		if (a->size + b->size == tmp->size_ini)
		{
			tmp->range_ini = tmp->range_end + 1;
			tmp->range_end = tmp->range_end + 25;
			tmp->num = 25;
		}
		tmp->chunks--;
	}
}

static void	push_sorted(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		if (b->top->index == b->size)
			push(b, a, STACK_A);
		else if (find_bot(b) >= b->size / 2)
			reverse_rotate(b, STACK_B);
		else
			rotate(b, STACK_B);
	}
}

// static void	number_of_chunks(t_aux *tmp, t_stack *a, t_stack *b)
// {
// 	tmp->chunks = a->size / 25;
// 	while (a->size)
// 	{
// 		while (b->size != tmp->range_end && a->size != 0)
// 		{

// 		}
// 		if (a->size + b->size == tmp->size_ini)
// 		{
// 			tmp->range_ini = tmp->range_end + 1;
// 			tmp->range_end = tmp->range_end + 25;
// 			tmp->num = 25;
// 		}
// 		tmp->chunks--;
// 	}
// }

// static void	push_sorted(t_stack *a, t_stack *b)
// {
// 	while (b->size)
// 	{
// 		if (b->top->index == b->size)
// 			push(b, a, STACK_A);
// 		else if (find_bot(b) >= b->size / 2)
// 			reverse_rotate(b, STACK_B);
// 		else
// 			rotate(b, STACK_B);
// 	}
// }

int	the_rest(t_stack *a, t_stack *b)
{
	t_aux	tmp;

	tmp.num = 25;
	tmp.chunks = 0;
	tmp.range_ini = 1;
	tmp.range_end = 25;
	tmp.size_ini = a->size;
	(void)b;
	if (a->size >= 6)
	{
		number_of_chunks(&tmp, a, b);
		push_sorted(a, b);
	}
	return (FALSE);
}
