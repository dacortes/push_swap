/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:06:27 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/13 12:49:36 by dacortes         ###   ########.fr       */
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

/*int	setup_stack(int ac, char **av, t_stack *stack)
{
	t_aux	tmp;

	tmp.data = ft_calloc(ac - 1, sizeof(int));
	tmp.index = ft_calloc(ac - 1, sizeof(int));
	if (!tmp.data || !tmp.index)
		return (ERROR);
	tmp.num = 0;
	tmp.next = 1;
	tmp.index_ = 1;
	while (tmp.next < ac)
	{
		tmp.index[tmp.num] = tmp.index_++;
		tmp.data[tmp.num++] = ft_atoi(av[tmp.next++]);
	}
	tmp.num = 0;
	while (tmp.num < ac -1)
	{
		tmp.next = tmp.num + 1;
		while (tmp.next < ac - 1)
		{
			if (tmp.data[tmp.num] < tmp.data[tmp.next])
			{
				tmp.tmp = tmp.index[tmp.num];
				tmp.index[tmp.num] = tmp.index[tmp.next];
				tmp.index[tmp.next] = tmp.tmp;
			}
			tmp.next++;
		}
		tmp.num++;
	}
	tmp.num = ac - 1;
	tmp.next = ac - 2;
	while (av[tmp.num] && tmp.num != 0)
	{
		push_stack(stack, ft_atoi(av[tmp.num]), tmp.index[tmp.next]);
		tmp.num--;
		tmp.next--;
	}
	free(tmp.data);
	free(tmp.index);
	return (SUCCESS);
}*/
/*int	setup_stack(int ac, char **av, t_stack *stack)
{
	t_aux	tmp;
	int	min_index;
	int min_num;
	(void) stack;
	tmp.data = ft_calloc(ac - 1, sizeof(int));
	tmp.index = ft_calloc(ac - 1, sizeof(int));
	if (!tmp.data || !tmp.index)
		return (ERROR);
	tmp.num = 0;
	tmp.next = 1;
	min_index = 1;
	while (tmp.next < ac)
	{
		//tmp.index[tmp.num] = tmp.num;
		tmp.data[tmp.num++] = ft_atoi(av[tmp.next++]);
	}
	tmp.num = 0;
	while (tmp.num < ac - 1)
		ft_printf(R"%d, "E, tmp.data[tmp.num++]);
	ft_printf("\n");
	tmp.num = 0;
	tmp.next = 1;
	ft_printf(B"%d\n"E, min_index);
	while (tmp.num < ac - 1)
	{
		tmp.next = tmp.num + 1;
		while (tmp.next < ac - 1)
		{
			if (tmp.data[tmp.num] > tmp.data[tmp.next])
			{
				min_num = tmp.data[tmp.next];
				tmp.index[tmp.next] = min_index;
				min_index++;
			}
			tmp.next++;
		}
		tmp.num++;
	}
	ft_printf("\n%d", min_num);
	ft_printf("\n");
	tmp.num = 0;
	while (tmp.num < ac - 1)
		ft_printf(Y"%d, "E, tmp.index[tmp.num++]);
	ft_printf("\n");
	free(tmp.data);
	free(tmp.index);
	return (SUCCESS);
}*/
int	setup_stack(int ac, char **av, t_stack *stack)
{
	t_aux	tmp;
	int	min_index;
	(void) stack;
	tmp.data = ft_calloc(ac - 1, sizeof(int));
	tmp.index = ft_calloc(ac - 1, sizeof(int));
	if (!tmp.data || !tmp.index)
		return (ERROR);
	tmp.num = 0;
	tmp.next = 1;
	while (tmp.next < ac)
	{
		tmp.data[tmp.num++] = ft_atoi(av[tmp.next++]);
	}
	tmp.num = 0;
	while (tmp.num < ac - 1)
		ft_printf(R"%d, "E, tmp.data[tmp.num++]);
	ft_printf("\n");
	tmp.num = 0;
	min_index = 1;
	while (tmp.num < ac - 1)
	{
		tmp.next = 0;
		min_index = 1;
		while (tmp.next < ac - 1)
		{
			if (tmp.data[tmp.num] > tmp.data[tmp.next])
			{
				min_index++;
			}
			tmp.next++;
		}
		tmp.index[tmp.num] = min_index;
		tmp.num++;
	}
	ft_printf("\n");
	tmp.num = 0;
	while (tmp.num < ac - 1)
		ft_printf(Y"%d, "E, tmp.index[tmp.num++]);
	ft_printf("\n");
	tmp.num = ac - 1;
	tmp.next = ac - 2;
	while (av[tmp.num] && tmp.num != 0)
	{
		push_stack(stack, ft_atoi(av[tmp.num]), tmp.index[tmp.next]);
		tmp.num--;
		tmp.next--;
	}
	free(tmp.data);
	free(tmp.index);
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
