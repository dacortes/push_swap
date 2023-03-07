/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:06:27 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/07 15:39:03 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

int	stack_init(t_stack **stack)
{
	*stack = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!stack)
		return (ERROR);
	(*stack)->size = 0;
	(*stack)->top = NULL;
	(*stack)->bot = NULL;
	return (SUCCES);
}

void	stack_destroy(t_stack *destroy)
{
	t_element	*elem;

	while (destroy->top != NULL)
	{
		elem = destroy->top;
		destroy->top = destroy->top->next;
		free(elem);
	}
	free(destroy);
}

int main(void)
{
	t_stack	*a;

	stack_init(&a);
	stack_destroy(a);
	return (SUCCES);
}