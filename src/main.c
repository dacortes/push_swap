/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:06:27 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/17 11:45:20 by dacortes         ###   ########.fr       */
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
	t_node *nod;
	
	check_arg(ac, av);
	double_init(&a, &b);
	setup_stack(av, a);
	push(a, b, PUSH_B);
	nod = b->top;
	ft_printf(Y"%d\n"E, nod->data);
	push(a, b, PUSH_B);
	nod = b->top;
	ft_printf(Y"%d\n"E, nod->data);
	push(a, b, PUSH_B);
	nod = b->top;
	ft_printf(Y"%d\n"E, nod->data);
	stack_printf(a);
	stack_destroy(a);
	stack_destroy(b);
	return (SUCCES);
}
