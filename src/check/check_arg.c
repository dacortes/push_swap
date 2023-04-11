/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:20:00 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/11 16:43:10 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	check_arg(int ac, char **av)
{
	if (ac <= 1)
	{
		ft_printf(R"Error\n"E);
		exit (ERROR);
	}
	else if (check_av(av) == ERROR || check_num(ac, av) == ERROR
		|| check_duplicate(ac, av) == ERROR)
	{
		ft_printf(R"Error\n"E);
		exit (ERROR);
	}
	else if (check_av(av) == SUCCESS && check_num(ac, av) == ERROR
		&& check_duplicate(ac, av) == ERROR)
	{
		ft_printf(R"Error\n"E);
		exit (ERROR);
	}
	return (SUCCESS);
}

int	check_av(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		if (ft_strlen(av[i]) == 1 && av[i][j] == '-')
			return (ERROR);
		if (ft_strlen(av[i]) == 1 && av[i][j] == '+')
			return (ERROR);
		if (av[i][0] == '+' || av[i][0] == '-')
			++j;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				++j;
			else
				return (ERROR);
		}
		j = 0;
		++i;
	}
	return (SUCCESS);
}

int	check_num(int ac, char **av)
{
	int	i;
	int	size;

	i = 1;
	while (i < ac)
	{
		size = ft_strlen(av[i]);
		if (size == 0 || ((size > 10 && av[i][0] != '-')
			&& (size > 10 && av[i][0] != '+')) || size > 11)
			return (ERROR);
		if (av[i][0] != '-' && size == 10 &&
			ft_strncmp(av[i], "2147483647", 10) > 0)
			return (ERROR);
		if (av[i][0] == '-' && size == 11 &&
			ft_strncmp(av[i], "-2147483648", 11) > 0)
			return (ERROR);
		if (av[i][0] == '+' && size == 11 &&
			ft_strncmp(av[i], "+2147483647", 11) > 0)
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}

int	check_duplicate(int ac, char **av)
{
	int	num;
	int	next;

	num = 1;
	while (num < ac)
	{
		next = num + 1;
		while (next < ac)
		{
			if (ft_strncmp(av[num], av[next], ft_strlen(av[num])) == 0)
				return (ERROR);
			++next;
		}	
		++num;
	}
	return (SUCCESS);
}

int	is_stack_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node && node->next)
	{
		if (node->data > node->next->data)
			return (FALSE);
		node = node->next;
	}
	return (TRUE);
}
