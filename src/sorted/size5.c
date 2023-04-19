/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:30:10 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/19 11:12:31 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	the_size_is_five(t_stack *a, t_stack *b)
{
	int	index;

	index = 5;
	while (index != a->top->index)
	{
		reverse_rotate(a, REV_ROTATE_A);
		if (a->top->index == 4)
			push(a, b, PUSH_B);
	}
	push(a, b, PUSH_B);
	index--;
	if (b->size != 2)
	{
		while (index != a->top->index)
			reverse_rotate(a, REV_ROTATE_A);
	}
	push(a, b, PUSH_B);
	the_size_is_three(a);
	push(b, a, PUSH_B);
	rotate(a, ROTATE_A);
	push(b, a, PUSH_B);
	rotate(a, ROTATE_A);
	return (SUCCESS);
}
