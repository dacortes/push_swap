/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:06:27 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/07 22:12:15 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void stack_printf(t_stack	*sactk)
{
	t_node	*nod;

	nod = sactk->top;
	while (nod)
	{
		ft_printf("%d\n", nod->data);
		nod = nod->next;
	}
}

int	main(void)
{
	t_stack	*a;
	
	if(stack_init(&a) == ERROR)
	{
		ft_printf(R"Error: cannot initialize stack\n"E);
		return(ERROR);
	}
	push_num(a, 10);
	push_num(a, 20);
	push_num(a, 50);
	stack_printf(a);
	stack_destroy(a);
	return (SUCCES);
}
