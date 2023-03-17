/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:19:38 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/17 11:46:50 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

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

int	double_init(t_stack **one, t_stack **two)
{
	if (stack_init(one) == ERROR || stack_init(two) == ERROR)
		{
			ft_printf(R"Error\n"E);
			exit (ERROR);
		}
	return (SUCCES);
}