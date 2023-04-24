/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:56:09 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/24 12:12:53 by dacortes         ###   ########.fr       */
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
int	find_bot(t_stack *stack)
{
	t_node *node;
	int pos;

	pos = 1;
	node = stack->top;
	while (node)
	{
		node = node->next;
		if (node->index == stack->size)
			break;
		pos++;
	}
	return (pos);
}

int	the_rest(t_stack *a, t_stack *b)
{
	int size_ini;
	int	chunks;
	int	i = 25;
	int	range_ini;
	int	range_end;

	chunks = 0;
	range_ini = 1;
	range_end = 25;
	size_ini = a->size;
	if (a->size < 50)
		chunks = 2;
	else if (a->size >= 50)
	{
		chunks = a->size / 25;
		while (a->size)
		{
			while (b->size != range_end && a->size != 0)
			{
				if (a->top->index >= range_ini && a->top->index <= range_end)
				{
					push(a, b, STACK_B);
					if (b->size > 2 && b->top->index <= ((range_end - range_ini)/2) + range_ini)
						rotate(b, STACK_B);
					--i;
				}
				reverse_rotate(a, STACK_A);
			}
			if (a->size + b->size == size_ini)
			{
				range_ini = range_end + 1;
				range_end = range_end + 25;
				i = 25;
			}
			chunks--;
		}
		i = b->size;
		while (b->size)
		{
			if (b->top->index == i)
			{
				push(b, a, STACK_A);
				i--;
			}
			else if (find_bot(b) >= b->size/2)
				reverse_rotate(b, STACK_B);
			else
				rotate(b, STACK_B);
		}
		if (is_stack_sorted(a, AS))
			ft_printf(G"OK\n"E);
	}
	
	return (FALSE);
}
