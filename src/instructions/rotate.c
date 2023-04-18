/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:10:41 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/18 11:19:21 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	rotate(t_stack *stack, int type_rotate)
{
	t_node	*top;
	t_node	*bot;
	t_node	*prev;

	if (stack->size < 2)
	{
		ft_printf(B"%d"E,stack->size);
		return (ERROR);
	}
	if (type_rotate == ROTATE_A)
		ft_printf("ra\n");
	if (type_rotate == ROTATE_B)
		ft_printf("rb\n");
	top = stack->top;
	bot = stack->bot;
	prev = top->prev;
	stack->top = top->next;
	stack->bot = top;
	top->next = NULL;
	bot->next = top;
	top->prev = bot;
	stack->top->prev = prev;
	return (SUCCESS);
}

int	rotate_rotate(t_stack *one, t_stack *two, int type_rotate)
{
	if (one->size < 2 || two->size < 2)
		return (ERROR);
	else if (!one || !two || !one->bot || !two->bot)
		return (ERROR);
	rotate(one, type_rotate);
	rotate(two, type_rotate);
	ft_printf("rr\n");
	return (SUCCESS);
}
