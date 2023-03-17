/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:10:23 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/17 13:30:02 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	reverse_rotate(t_stack *stack, int type_reverse_rotate)
{
	t_node *bot;
	t_node *prev_bot;

	if (stack->size < 2)
		return (FALSE);
	bot = stack->bot;
	prev_bot = stack->bot->prev;
	prev_bot->next = NULL;
	bot->next = stack->top;
	stack->top->prev = bot;
	stack->top = bot;
	stack->bot = prev_bot;
	if (type_reverse_rotate == REV_ROTATE_A)
		ft_printf("rra\n");
	if (type_reverse_rotate == REV_ROTATE_B)
		ft_printf("rrb\n");
	return (SUCCES);
}

int	double_rrr(t_stack *one, t_stack *two, int type_reverse_rotate)
{
	if (one->size < 2 || two->size < 2)
		return (FALSE);
	else if (!one || !two || !one->bot || !two->bot)
		return (FALSE);
	reverse_rotate(one, 0);
	reverse_rotate(two, 0);
	ft_printf("rrr\n");
	return (SUCCES);
}