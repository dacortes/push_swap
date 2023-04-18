/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:56:09 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/18 12:36:00 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	is_stack_sorted(t_stack *stack, int type)
{
	t_node	*node;

	
	if (type == AS)
	{
		node = stack->top;
		while (node && node->next)
		{
			if (node->data > node->next->data)
				return (FALSE);
			node = node->next;
		}
	}
	if (type == DES)
	{
		node = stack->bot;
		while (node && node->prev)
		{
			if (node->data > node->prev->data)
				return (FALSE);
			node = node->prev;
		}
	}
	return (TRUE);
}
static int	the_size_is_four(t_stack *a, t_stack *b)
{
	int	index;
	int	if_possible;

	index = 1;
	if_possible = SUCCESS;
	if (is_stack_sorted(a, DES))
	{
		reverse_rotate(a, REV_ROTATE_A);
		push(a, b, PUSH_B);
		swap(a, SWAP);
		reverse_rotate(a, REV_ROTATE_A);
		push(b, a, PUSH_A);
		return (SUCCESS);
	}
	push(a, b, PUSH_B);
	push(a, b, PUSH_B);
	ft_printf("Antes de los condicionales\n");
	stack_printf(b);
	ft_printf("-----------------\n");
	swap(b, SWAP_B);
	push(a, b, PUSH_B);
	ft_printf("Antes de aplicar el rrb\n");
	stack_printf(b);
	ft_printf("-----------------\n");
	ft_printf("%d\n", b->size);
	stack_printf(b);
	rotate(b, ROTATE_B);
	//reverse_rotate(b, ROTATE_B);
	ft_printf(G"Stack B\n"E);
	stack_printf(b);
	return (SUCCESS);
}

int	small_stack_size(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size == 2)
	{
		if (is_stack_sorted(a, DES) == TRUE)
			swap(a, SWAP_A);
		return (TRUE);
	}
	if (a->size == 3)
	{
		while (is_stack_sorted(a, AS) == FALSE)
		{
			swap(a, SWAP_A);
			reverse_rotate(a, REV_ROTATE_A);
		}
		return (TRUE);
	}
	if (a->size == 4)
	{
		the_size_is_four(a , b);
		return (TRUE);
	}
	if (a->size == 5)
		return (TRUE);
	return (FALSE);
}

int sort_stack()
{
	return (SUCCESS);
}