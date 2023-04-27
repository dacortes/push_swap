/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_rest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:17:52 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/27 19:21:01 by dacortes         ###   ########.fr       */
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

// static void	number_of_chunks(t_aux *tmp, t_stack *a, t_stack *b)
// {
// 	tmp->chunks = a->size / 25;
// 	while (a->size)
// 	{
// 		while (b->size != tmp->range_end && a->size != 0)
// 		{
// 			if (a->top->index >= tmp->range_ini
// 				&& a->top->index <= tmp->range_end)
// 			{
// 				push(a, b, STACK_B);
// 				if (b->size > 2 && b->top->index
// 					<= ((tmp->range_end - tmp->range_ini) / 2) + tmp->range_ini)
// 					rotate(b, STACK_B);
// 				tmp->num--;
// 			}
// 			reverse_rotate(a, STACK_A);
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

int find_min_pos(t_aux *tmp, t_stack *stack)
{
	t_node *node;
	int range;
	int num_pos;
	int min_pos;

	num_pos = 0;
	node = stack->top;
	min_pos = stack->size;
	while (node)
	{
		range = node->index >= tmp->range_ini
			&& node->index <= tmp->range_end;
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

int find_max_pos(t_aux *tmp, t_stack *stack)
{
    t_node *node;
    int max_pos;
	int	pos;

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
    return max_pos;
}


void range(t_aux *tmp, t_stack *stack)
{
	t_node *node;
	int range;
	int min_pos = stack->size;

	node = stack->top;
	while (node)
	{
		range = node->index >= tmp->range_ini
			&& node->index <= tmp->range_end;
		if (range)
		{
			int num_pos = find_num(stack, node->index);
			if (num_pos < min_pos)
				min_pos = num_pos;
			ft_printf(G"number: %d     pos: %d\n"E, node->index, num_pos);
		}
		node = node->next;
	}
}

static void	number_of_chunks(t_aux *tmp, t_stack *a, t_stack *b)
{
	int case1 = 0;
	while (a->size)
	{
		while (b->size != tmp->range_end && a->size != 0)
		{
			case1 = a->top->index >= tmp->range_ini 
 				&& a->top->index <= tmp->range_end;
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
				rotate(a , STACK_A);
			else
				reverse_rotate(a, STACK_A);
		}
		if (a->size + b->size == tmp->size_ini)
		{
			tmp->range_ini = tmp->range_end + 1;
			tmp->range_end = tmp->range_end + 25;
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

	tmp.range_ini = 1;
	tmp.range_end = 25;
	tmp.size_ini = a->size;
	(void)b;
	if (a->size >= 6)
	{
		number_of_chunks(&tmp, a, b);
		push_sorted(a, b);
		// ft_printf("Min position:%d\n", find_min_pos(&tmp, a));
		// ft_printf("Max position:%d\n", find_max_pos(&tmp, a));
	}
	// if (is_stack_sorted(a, AS))
	// 	ft_printf(G"OK\n"E);
	// else
	// 	ft_printf(R"KO\n"E);
	return (FALSE);
}
