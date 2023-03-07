/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:25:09 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/07 18:42:57 by dacortes         ###   ########.fr       */
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
