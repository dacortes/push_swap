/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:17:52 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/24 15:26:49 by dacortes         ###   ########.fr       */
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
		if (node->index == stack->size)
			break ;
		pos++;
	}
	return (pos);
}

// int	the_rest(t_stack *a, t_stack *b)
// {
// 	int size_ini;
// 	int	chunks;
// 	int	i = 25;
// 	int	range_ini;
// 	int	range_end;

// 	chunks = 0;
// 	range_ini = 1;
// 	range_end = 25;
// 	size_ini = a->size;
// 	if (a->size >= 6)
// 	{
// 		chunks = a->size / 25;
// 		while (a->size)
// 		{
// 			while (b->size != range_end && a->size != 0)
// 			{
// 				if (a->top->index >= range_ini && a->top->index <= range_end)
// 				{
// 					push(a, b, STACK_B);
// 					if (b->size > 2 && b->top->index <= ((range_end - range_ini)/2) + range_ini)
// 						rotate(b, STACK_B);
// 					--i;
// 				}
// 				reverse_rotate(a, STACK_A);
// 			}
// 			if (a->size + b->size == size_ini)
// 			{
// 				range_ini = range_end + 1;
// 				range_end = range_end + 25;
// 				i = 25;
// 			}
// 			chunks--;
// 		}
// 		i = b->size;
// 		while (b->size)
// 		{
// 			if (b->top->index == i)
// 			{
// 				push(b, a, STACK_A);
// 				i--;
// 			}
// 			else if (find_bot(b) >= b->size/2)
// 				reverse_rotate(b, STACK_B);
// 			else
// 				rotate(b, STACK_B);
// 		}
// 		// if (is_stack_sorted(a, AS))
// 		// 	ft_printf(G"OK\n"E);
// 	}
	
// 	return (FALSE);
// }
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

static void	push_sorted(t_aux *tmp, t_stack *a, t_stack *b)
{
	tmp->num = b->size;
	while (b->size)
	{
		if (b->top->index == tmp->num)
		{
			push(b, a, STACK_A);
			tmp->num--;
		}
		else if (find_bot(b) >= b->size / 2)
			reverse_rotate(b, STACK_B);
		else
			rotate(b, STACK_B);
	}
}

int	the_rest(t_stack *a, t_stack *b)
{
	t_aux	tmp;

	tmp.num = 25;
	tmp.chunks = 0;
	tmp.range_ini = 1;
	tmp.range_end = 25;
	tmp.size_ini = a->size;
	if (a->size >= 6)
	{
		number_of_chunks(&tmp, a, b);
		push_sorted(&tmp, a, b);
	}
	return (FALSE);
}
