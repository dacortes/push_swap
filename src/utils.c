/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:53:09 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/27 18:55:00 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	stack_printf(t_stack	*sactk)
{
	t_node	*nod;

	nod = sactk->top;
	while (nod)
	{
		ft_printf(R"node:%p next:%p prev:%p\n"E, nod, nod->next, nod->prev);
		ft_printf(G"data :%d\n"E, nod->data);
		ft_printf(Y"index:%d\n"E, nod->index);
		nod = nod->next;
	}
}

void	node_printf(t_node	*node, int type)
{
	t_node	*nod;

	nod = node;
	if (type == NEXT_)
	{
		while (nod)
		{
			ft_printf(B"%d\n"E, nod->data);
			ft_printf(Y"%d\n"E, nod->index);
			nod = nod->next;
		}
	}
	if (type == PREV_)
	{
		while (nod)
		{
			ft_printf(B"%d\n"E, nod->data);
			ft_printf(Y"%d\n"E, nod->index);
			nod = nod->prev;
		}
	}
}

// void range(t_aux *tmp, t_stack *stack)
// {
// 	t_node *node;
// 	int range;
// 	int min_pos = stack->size;

// 	node = stack->top;
// 	while (node)
// 	{
// 		range = node->index >= tmp->range_ini
// 			&& node->index <= tmp->range_end;
// 		if (range)
// 		{
// 			int num_pos = find_num(stack, node->index);
// 			if (num_pos < min_pos)
// 				min_pos = num_pos;
// 			ft_printf(G"number: %d     pos: %d\n"E, node->index, num_pos);
// 		}
// 		node = node->next;
// 	}
// 	ft_printf("Minimum position: %d\n", min_pos);
// }