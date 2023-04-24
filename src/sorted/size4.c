/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:50:54 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/19 12:11:26 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

static void	is_descending(t_stack *a, t_stack *b)
{
	if (is_stack_sorted(a, DES))
	{
		reverse_rotate(a, STACK_A);
		push(a, b, STACK_B);
		swap(a, STACK_A);
		reverse_rotate(a, STACK_A);
		push(b, a, STACK_A);
	}
}

int	the_size_is_four(t_stack *a, t_stack *b)
{
	int	index;

	index = 1;
	is_descending(a, b);
	while (index != a->top->index)
		rotate(a, STACK_A);
	push(a, b, STACK_B);
	index++;
	while (index != a->top->index)
		rotate(a, STACK_A);
	if (is_stack_sorted(a, AS))
	{
		push(b, a, STACK_A);
		return (SUCCESS);
	}
	push(b, a, STACK_A);
	if (!is_stack_sorted(a, AS))
	{
		push(a, b, STACK_B);
		push(a, b, STACK_B);
		swap(a, STACK_A);
		push(b, a, STACK_A);
		push(b, a, STACK_A);
	}
	return (SUCCESS);
}
