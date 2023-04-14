/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:12:45 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/14 13:06:40 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	push_stack(t_stack *stack, int data, int index)
{
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(sizeof(t_node), 1);
	if (!new_node)
		return (ERROR);
	new_node->data = data;
	new_node->index = index;
	new_node->next = NULL;
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bot = new_node;
		stack->bot->prev = NULL;
	}
	else
	{
		new_node->next = stack->top;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
	stack->size++;
	return (SUCCESS);
}

int	pop_stack(t_stack *stack)
{
	t_node	*temp;
	int		data;
	int		index;

	if (!stack || !stack->top)
		return (ERROR);
	temp = stack->top;
	data = temp->data;
	index = temp->index;
	stack->top = temp->next;
	if (!stack->top)
		stack->bot = NULL;
	else
	{
		stack->top->prev = NULL;
		stack->bot = stack->top;
		while (stack->bot->next)
			stack->bot = stack->bot->next;
	}
	free(temp);
	stack->size--;
	if (stack->size == 0)
		stack->bot = NULL;
	return (data);
}

int	push(t_stack *scr, t_stack *dst, int type_push)
{
	t_node	*nod;

	if (!scr || !scr->top)
		return (ERROR);
	nod = scr->top;
	push_stack(dst, nod->data, nod->index);
	pop_stack(scr);
	if (type_push == PUSH_A)
		ft_printf("pa\n");
	if (type_push == PUSH_B)
		ft_printf("pb\n");
	return (SUCCESS);
}
