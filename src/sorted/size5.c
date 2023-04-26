/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:30:10 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/26 10:55:18 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	the_size_is_five(t_stack *a, t_stack *b)
{
	int	index;

	index = a->size;
	while (a->size != 3)
	{
		if (a->top->index == index || a->top->index == (index - 1))
			push(a, b, STACK_B);
		else if (find_num(a, 5) == 2 || find_num(a, 4) == 2)
			rotate(a, STACK_A);
		else if (find_num(a, 5) >= 3 || find_num(a, 4) >= 3)
			reverse_rotate(a, STACK_A);
	}
	the_size_is_three(a);
	if (is_stack_sorted(b, AS))
		swap(b, STACK_B);
	while (b->size)
		push(b, a, STACK_A);
	rotate(a, STACK_A);
	rotate(a, STACK_A);
	return (SUCCESS);
}
