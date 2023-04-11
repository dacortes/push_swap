/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:06:27 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/11 17:07:17 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	stack_printf(t_stack	*sactk)
{
	t_node	*nod;

	nod = sactk->top;
	while (nod)
	{
		ft_printf(G"%d\n"E, nod->data);
		nod = nod->next;
	}
}

void	node_printf(t_node	*node, int type)
{
	t_node	*nod;

	nod = node;

	if (type == NEXT_)
	{
		while (nod)
		{
			ft_printf(B"%d\n"E, nod->data);
			nod = nod->next;
		}
	}
	if (type == PREV_)
	{
		while (nod)
		{
			ft_printf(B"%d\n"E, nod->data);
			nod = nod->prev;
		}
	}
}

void	setup_stack(int ac, char **av, t_stack *stack)
{
	int	i;

	i = ac - 1;
	while (av[i] && i != 0)
		push_stack(stack, ft_atoi(av[i--]));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack *b;
	
	check_arg(ac, av);
	double_init(&a, &b);
	setup_stack(ac, av, a);
	if (is_stack_sorted(a) == FALSE)
		ft_printf(B"You can work\n"E);
	else
	{
		double_destroy(a, b);
		return (SUCCESS);
	}
	stack_printf(a);
	push(a, b, PUSH_B);
	push(a, b, PUSH_B);
	push(a, b, PUSH_B);
	ft_printf(B"Stack A\n"E);
	stack_printf(a);
	ft_printf(B"Stack B\n"E);
	stack_printf(b);
	double_destroy(a, b);
	return (SUCCESS);
}
