/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:17:52 by dacortes          #+#    #+#             */
/*   Updated: 2023/05/02 16:16:10 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

static void	axu_chunks(t_aux *tmp, t_stack *a, t_stack *b, int case1)
{
	if (case1)
	{
		push(a, b, STACK_B);
		if (b->size > 2 && b->top->index
			<= ((tmp->range_end - tmp->range_ini) / 2) + tmp->range_ini)
			rotate(b, STACK_B);
	}
	else if (find_min_pos(tmp, a) > find_max_pos(tmp, a))
		reverse_rotate(a, STACK_A);
	else if (find_min_pos(tmp, a) < find_max_pos(tmp, a))
		rotate(a, STACK_A);
	else if (find_min_pos(tmp, a) == 2 && find_min_pos(tmp, a) != (a->size - 1))
		swap(a, STACK_A);
	else if (find_min_pos(tmp, a) != 2 && find_min_pos(tmp, a) == (a->size - 1))
		reverse_rotate(a, STACK_A);
	else if (find_min_pos(tmp, a) != 2 && find_min_pos(tmp, a) == (a->size - 2))
	{
		reverse_rotate(a, STACK_A);
		reverse_rotate(a, STACK_A);
	}
	else
		reverse_rotate(a, STACK_A);
}

static void	number_of_chunks(t_aux *tmp, t_stack *a, t_stack *b)
{
	int	case1;

	case1 = 0;
	while (a->size)
	{
		while (b->size != tmp->range_end && a->size != 0)
		{
			case1 = (a->top->index >= tmp->range_ini \
				&& a->top->index <= tmp->range_end);
			axu_chunks(tmp, a, b, case1);
		}
		if (tmp->size_ini <= 100)
		{
			tmp->range_ini = tmp->range_end + 1;
			tmp->range_end = tmp->range_end + 25;
		}
		else if (tmp->size_ini > 100)
		{
			tmp->range_ini = tmp->range_end + 1;
			tmp->range_end = tmp->range_end + (a->size / 4) + 1;
		}
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

int	the_rest(t_stack *a, t_stack *b)
{
	t_aux	tmp;

	tmp.size_ini = a->size;
	if (tmp.size_ini <= 100)
	{
		tmp.range_ini = 1;
		tmp.range_end = 25;
	}
	else if (tmp.size_ini > 100)
	{
		tmp.range_ini = 1;
		tmp.range_end = a->size / 4;
	}
	number_of_chunks(&tmp, a, b);
	push_sorted(a, b);
	return (FALSE);
}
