/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:06:27 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/10 15:27:31 by dacortes         ###   ########.fr       */
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
	
	check_arg(ac, av);
	stack_init(&a);
	setup_stack(av, a);
	stack_printf(a);
	stack_destroy(a);
	return (SUCCES);
}
