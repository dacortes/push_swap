/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:06:27 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/05 17:44:44 by dacortes         ###   ########.fr       */
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
	//t_node *nod;
	
	check_arg(ac, av);
	double_init(&a, &b);
	setup_stack(av, a);
	stack_printf(a);
	push(a, b, PUSH_B);
	push(a, b, PUSH_B);
	push(a, b, PUSH_B);
	ft_printf(B"Stack a\n"E);
	stack_printf(a);
	ft_printf(B"Stack b\n"E);
	stack_printf(b);
	ft_printf(G"Apply ss\n"E);
	swap_swap(a, b);
	ft_printf(B"Res\nStack a\n"E);
	stack_printf(a);
	ft_printf(B"Stack b\n"E);
	stack_printf(b);

	/*ft_printf(B"Se le aplica rra\n"E);
	reverse_rotate(a, REV_ROTATE_A);
	stack_printf(a);
	ft_printf(B"Se le aplica rrb\n"E);
	reverse_rotate(b, REV_ROTATE_B);
	stack_printf(b);
	double_destroy(a, b);*/
	return (SUCCESS);
}
