/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:19:38 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/05 16:44:46 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

static int	stack_init(t_stack **stack)
{
	*stack = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!stack)
		return (ERROR);
	(*stack)->size = 0;
	(*stack)->top = NULL;
	(*stack)->bot = NULL;
	return (SUCCESS);
}

int	double_init(t_stack **one, t_stack **two)
{
	if (stack_init(one) == ERROR || stack_init(two) == ERROR)
		{
			ft_printf(R"Error\n"E);
			exit (ERROR);
		}
	return (SUCCESS);
}