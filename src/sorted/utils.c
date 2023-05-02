/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:04:26 by dacortes          #+#    #+#             */
/*   Updated: 2023/05/02 13:07:12 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	find_num(t_stack *stack, int num)
{
	t_node	*node;
	int		pos;

	pos = 1;
	node = stack->top;
	while (node)
	{
		if (node->index == num)
			break ;
		node = node->next;
		pos++;
	}
	return (pos);
}

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

int	find_min_pos(t_aux *tmp, t_stack *stack)
{
	t_node	*node;
	int		range;
	int		num_pos;
	int		min_pos;

	num_pos = 0;
	node = stack->top;
	min_pos = stack->size;
	while (node)
	{
		range = (node->index >= tmp->range_ini \
			&& node->index <= tmp->range_end);
		if (range)
		{
			num_pos = find_num(stack, node->index);
			if (num_pos < min_pos)
				min_pos = num_pos;
		}
		node = node->next;
	}
	return (min_pos);
}

int	find_max_pos(t_aux *tmp, t_stack *stack)
{
	t_node	*node;
	int		max_pos;
	int		pos;

	pos = 0;
	max_pos = 0;
	node = stack->top;
	while (node)
	{
		if (node->index >= tmp->range_ini
			&& node->index <= tmp->range_end)
		{
			pos = find_num(stack, node->index);
			if (pos > max_pos)
				max_pos = pos;
		}
		node = node->next;
	}
	return (max_pos);
}
