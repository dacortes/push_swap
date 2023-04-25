/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:30:10 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/25 11:01:12 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	the_size_is_five(t_stack *a, t_stack *b)
{
	int	index;

	index = a->size;
	while (a->size)
	{
		if (a->top->index == (index - 1) || a->top->index == index)
		{
			push(a, b, STACK_B);
			if (a->size == 3)
				break ;
		}
		reverse_rotate(a, STACK_A);
	}
	if (!is_stack_sorted(b, AS))
		swap(b, STACK_B);
	the_size_is_three(a);
	while (b->size)
		push(b, a, STACK_A);
	swap(a, STACK_A);
	rotate(a, STACK_A);
	rotate(a, STACK_A);
	return (SUCCESS);
}