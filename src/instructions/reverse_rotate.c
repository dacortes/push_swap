/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:10:23 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/17 13:28:16 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	reverse_rotate(t_stack *stack, int type_reverse_rotate)
{
	t_node	*prev_bot;
	t_node	*top;
	t_node	*bot;

	if (stack->size < 2)
		return (ERROR);
	if (type_reverse_rotate == REV_ROTATE_A)
		ft_printf("rra\n");
	if (type_reverse_rotate == REV_ROTATE_B)
		ft_printf("rrb\n");
	if (stack->size == 2)
	{
		swap(stack, 0);
		return (SUCCESS);
	}
	top = stack->top;
	bot = stack->bot;
	prev_bot = bot->prev;
	if (!prev_bot)
	{
		top->prev = NULL;
		bot->next = top;
		stack->top = bot;
	}
	else
	{
		stack->bot = prev_bot;
		prev_bot->next = NULL;
		top->prev = bot;
		bot->next = top;
		stack->top = bot;
	}
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
