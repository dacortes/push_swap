/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:06:27 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/13 15:35:36 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

static int	axu_setup(int ac, char **av, t_aux *tmp)
{
	tmp->data = ft_calloc(ac - 1, sizeof(int));
	tmp->index = ft_calloc(ac - 1, sizeof(int));
	if (!tmp->data || !tmp->index)
		return (ERROR);
	tmp->num = 0;
	tmp->next = 1;
	while (tmp->next < ac)
		tmp->data[tmp->num++] = ft_atoi(av[tmp->next++]);
	tmp->num = 0;
	tmp->min_index = 1;
	while (tmp->num < ac - 1)
	{
		tmp->next = 0;
		tmp->min_index = 1;
		while (tmp->next < ac - 1)
		{
			if (tmp->data[tmp->num] > tmp->data[tmp->next])
				tmp->min_index++;
			tmp->next++;
		}
		tmp->index[tmp->num] = tmp->min_index;
		tmp->num++;
	}
	return (SUCCESS);
}

int	setup_stack(int ac, char **av, t_stack *stack)
{
	t_aux	tmp;

	if (axu_setup(ac, av, &tmp) == ERROR)
		return (ERROR);
	tmp.num = ac - 1;
	tmp.next = ac - 2;
	while (av[tmp.num] && tmp.num != 0)
		push_stack(stack, ft_atoi(av[tmp.num--]), tmp.index[tmp.next--]);
	free(tmp.data);
	free(tmp.index);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

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
