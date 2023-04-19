/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:10:23 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/19 11:01:39 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

static void	printf_rr(int type_reverse_rotate)
{
	if (type_reverse_rotate == REV_ROTATE_A)
		ft_printf("rra\n");
	if (type_reverse_rotate == REV_ROTATE_B)
		ft_printf("rrb\n");
}

static void	aux_rr(t_stack *stack, t_aux node)
{
	if (!node.prev_bot)
	{
		node.top->prev = NULL;
		node.bot->next = node.top;
		stack->top = node.bot;
	}
	else
	{
		stack->bot = node.prev_bot;
		node.prev_bot->next = NULL;
		node.top->prev = node.bot;
		node.bot->next = node.top;
		stack->top = node.bot;
		stack->top->prev = NULL;
	}
}

int	reverse_rotate(t_stack *stack, int type_reverse_rotate)
{
	t_aux	node;

	if (stack->size < 2)
		return (ERROR);
	printf_rr(type_reverse_rotate);
	if (stack->size == 2)
	{
		swap(stack, 0);
		return (SUCCESS);
	}
	node.top = stack->top;
	node.bot = stack->bot;
	node.prev_bot = node.bot->prev;
	aux_rr(stack, node);
	return (SUCCESS);
}

int	double_rrr(t_stack *one, t_stack *two, int type_reverse_rotate)
{
	if (one->size < 2 || two->size < 2)
		return (ERROR);
	else if (!one || !two || !one->bot || !two->bot)
		return (ERROR);
	reverse_rotate(one, type_reverse_rotate);
	reverse_rotate(two, type_reverse_rotate);
	ft_printf("rrr\n");
	return (SUCCESS);
}
