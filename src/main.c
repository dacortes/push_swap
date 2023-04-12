/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:06:27 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/12 19:47:41 by dacortes         ###   ########.fr       */
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

int	setup_stack(int ac, char **av, t_stack *stack)
{
	int	num;
	int	next;
	int in;
	int tmp;
	int	*data;
	int	*index;

	data = ft_calloc(ac - 1, sizeof(int));
	index = ft_calloc(ac - 1, sizeof(int));
	if (!index || !data)
		return (ERROR);
	num = 0;
	next = 1;
	in = 1;
	tmp = in;
	data[num] = 0;
	while (next < ac)
	{
		index[num] = in++;
		data[num++] = ft_atoi(av[next++]);
	}
	num = 0;
	while (num < ac -1)
	{
		next = num + 1;
		while (next < ac - 1)
		{
			if (data[num] > data[next])
			{
				tmp = index[num];
				index[num] = index[next];
				index[next] = tmp;
			}
			next++;
		}
		num++;
	}
	num = 0;
	while (num < ac - 1)
		ft_printf(Y"%d, "E, data[num++]);
	num = 0;
	ft_printf("\n");
	while (num < ac - 1)
		ft_printf(R"%d, "E, index[num++]);
	ft_printf("\n");
	num = ac - 1;
	next = ac - 2;
	while (av[num] && num != 0)
	{
		push_stack(stack, ft_atoi(av[num]), index[next]);
		num--;
		next--;
	}
	free(data);
	free(index);
	return (SUCCESS);
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
	/*push(a, b, PUSH_B);
	push(a, b, PUSH_B);
	push(a, b, PUSH_B);
	ft_printf(B"Stack A\n"E);
	stack_printf(a);
	ft_printf(B"Stack B\n"E);
	stack_printf(b);*/
	double_destroy(a, b);
	return (SUCCESS);
}
