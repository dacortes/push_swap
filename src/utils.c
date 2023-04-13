/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:53:09 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/13 14:54:07 by dacortes         ###   ########.fr       */
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
		ft_printf(Y"%d\n"E, nod->index);
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
			ft_printf(Y"%d\n"E, nod->index);
			nod = nod->next;
		}
	}
	if (type == PREV_)
	{
		while (nod)
		{
			ft_printf(B"%d\n"E, nod->data);
			ft_printf(Y"%d\n"E, nod->index);
			nod = nod->prev;
		}
	}
}