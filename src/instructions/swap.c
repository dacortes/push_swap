/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:09:48 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/17 13:16:37 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	swap(t_stack *stack, int type_swap)
{
	t_node	*top;
	t_node	*next;

	if (stack->size < 2)
		return (ERROR);
	top = stack->top;
	next = stack->top->next;
	stack->top = next;
	top->next = next->next;
	next->next = top;
	stack->top->prev = NULL;
	top->prev = stack->top;
	if (stack->size > 2)
		stack->top->next->next->prev = top;
	if (type_swap == SWAP_A)
		ft_printf("sa\n");
	if (type_swap == SWAP_B)
		ft_printf("sb\n");
	return (SUCCESS);
}

/*int	swap(t_stack *stack, int type_swap)
{
	t_node	*top;
	t_node	*next;

	if (stack->size < 2)
		return (ERROR);
	top = stack->top;
	next = stack->top->next;
	stack->top = next;
	top->next = next->next;
	next->next = top;
	if (type_swap == SWAP_A)
		ft_printf("sa\n");
	if (type_swap == SWAP_B)
		ft_printf("sb\n");
	return (SUCCESS);
}*/

int	swap_swap(t_stack *stack_one, t_stack *stack_tow)
{
	if (stack_one->size < 2 && stack_tow->size < 2)
		return (ERROR);
	swap(stack_one, 0);
	swap(stack_tow, 0);
	ft_printf("ss\n");
	return (SUCCESS);
}
