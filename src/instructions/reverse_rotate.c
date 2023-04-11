/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:10:23 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/11 10:13:35 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	reverse_rotate(t_stack *stack, int type_reverse_rotate)
{
	t_node	*top;
	t_node	*bot;

	(void) type_reverse_rotate;
	top = stack->top;
	bot = stack->bot;
	//node_printf(stack->bot, PREV_);
	//ft_printf("el stack bot es :%d", stack->bot->data);
	//node_printf(stack->bot->next);
	return (SUCCESS);
}

int	double_rrr(t_stack *one, t_stack *two, int type_reverse_rotate)
{
	if (one->size < 2 || two->size < 2)
		return (FALSE);
	else if (!one || !two || !one->bot || !two->bot)
		return (FALSE);
	reverse_rotate(one, type_reverse_rotate);
	reverse_rotate(two, type_reverse_rotate);
	ft_printf("rrr\n");
	return (SUCCESS);
}