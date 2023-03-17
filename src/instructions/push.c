/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:12:45 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/17 11:11:46 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	push_stack(t_stack *stack, int num)
{
	t_node *new_node;

	new_node = (t_node *)ft_calloc(sizeof(t_node), 1);
	if (!new_node)
		return (ERROR);
	new_node->data = num;
	new_node->next = NULL;
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bot = new_node;
	}
	else
	{
		new_node->next = stack->top;
		stack->top = new_node;
	}
	stack->size++;
	return (SUCCES);
}

int	pop_stack(t_stack *stack)
{
	int data;
	t_node *temp;

	if (!stack || !stack->top)
		return (FALSE);
	temp = stack->top;
	data = temp->data;
	stack->top = temp->next;
	if (!stack->top)
		stack->bot = NULL;
	free(temp);
	stack->size--;
	return (data);
}


int	push(t_stack *scr, t_stack *dst, int type_push)
{
	t_node *nod;

	if (!scr || !scr->top)
		return(FALSE);
	nod = scr->top;
	push_stack(dst,nod->data);
	pop_stack(scr);
	if (type_push == PUSH_A)
		ft_printf("pa\n");
	if (type_push == PUSH_B)
		ft_printf("pb\n");
	return(SUCCES);
}