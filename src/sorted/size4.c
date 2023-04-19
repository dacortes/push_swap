/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:50:54 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/18 17:24:14 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

static void	is_descending(t_stack *a, t_stack *b)
{
	if (is_stack_sorted(a, DES))
	{
		reverse_rotate(a, REV_ROTATE_A);
		push(a, b, PUSH_B);
		swap(a, SWAP);
		reverse_rotate(a, REV_ROTATE_A);
		push(b, a, PUSH_A);
	}
}

int	the_size_is_four(t_stack *a, t_stack *b)
{
	int	index;

	index = 1;
	is_descending(a, b);
	while (index != a->top->index)
		rotate(a, ROTATE_A);
	push(a, b, PUSH_B);
	index++;
	while (index != a->top->index)
		rotate(a, ROTATE_A);
	if (is_stack_sorted(a, AS))
	{
		push(b, a, PUSH_A);
		return (SUCCESS);
	}
	push(b, a, PUSH_A);
	if (!is_stack_sorted(a, AS))
	{
		push(a, b, PUSH_B);
		push(a, b, PUSH_B);
		swap(a, SWAP_A);
		push(b, a, PUSH_A);
		push(b, a, PUSH_A);
	}
	return (SUCCESS);
}
