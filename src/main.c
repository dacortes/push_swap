/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:06:27 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/11 14:54:25 by dacortes         ###   ########.fr       */
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

void	setup_stack(char **av, t_stack *stack)
{
	int	i;

	i = 1;
	while (av[i])
		push_stack(stack, ft_atoi(av[i++]));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack *b;
	
	check_arg(ac, av);
	double_init(&a, &b);
	setup_stack(av, a);
	stack_printf(a);
	push(a, b, PUSH_B);
	push(a, b, PUSH_B);
	push(a, b, PUSH_B);
	ft_printf(B"Stack A\n"E);
	stack_printf(a);
	ft_printf(B"Stack B\n"E);
	stack_printf(b);
	ft_printf(Y"Apply ra\n"E);
	rotate_rotate(a, b, 0);
	stack_printf(a);
	ft_printf(Y"Apply rb\n"E);
	stack_printf(b);
	/*ft_printf(B"Se le aplica rra\n"E);
	reverse_rotate(a, REV_ROTATE_A);
	stack_printf(a);
	ft_printf(B"Se le aplica rrb\n"E);
	reverse_rotate(b, REV_ROTATE_B);
	stack_printf(b);
	double_destroy(a, b);*/
	stack_destroy(a);
	stack_destroy(b);
	return (SUCCESS);
}
