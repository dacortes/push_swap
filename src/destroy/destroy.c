/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:25:09 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/11 10:16:11 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

void	stack_destroy(t_stack *stack)
{
	t_node	*elem;

	while (stack->top != NULL)
	{
		elem = stack->top;
		stack->top = stack->top->next;
		free(elem);
	}
	free(stack);
}

void	double_destroy(t_stack *one, t_stack *two)
{
	stack_destroy(one);
	stack_destroy(two);
}
