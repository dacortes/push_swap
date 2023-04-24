/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:30:10 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/19 12:18:07 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	the_size_is_five(t_stack *a, t_stack *b)
{
	int	index;

	index = 5;
	while (index != a->top->index)
	{
		reverse_rotate(a, STACK_A);
		if (a->top->index == 4)
			push(a, b, STACK_B);
	}
	push(a, b, STACK_B);
	index--;
	if (b->size != 2)
	{
		while (index != a->top->index)
			reverse_rotate(a, STACK_A);
	}
	push(a, b, STACK_B);
	the_size_is_three(a);
	push(b, a, STACK_A);
	rotate(a, STACK_A);
	push(b, a, STACK_A);
	rotate(a, STACK_A);
	return (SUCCESS);
}
