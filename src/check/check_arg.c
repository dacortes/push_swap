/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:20:00 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/10 12:14:19 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	check_ac(int ac, char **av)
{
	if (ac <= 1)
		exit (ERROR);
	else if (check_av(av) == ERROR || check_num(ac, av))
	{
		ft_printf(R"Error\n"E);
		exit (ERROR);
	}
	return (SUCCES);
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
	return (SUCCES);
}

int	check_num(int ac, char **av)
{
	{
	int	i;
	int	size;

	i = 1;
	while (i < ac)
	{
		size = ft_strlen(av[i]);
		if (size == 0 || ((size > 10 && av[i][0] != '-') && 
			(size > 10 && av[i][0] != '+')) || size > 11)
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
	return (SUCCES);
}
}
