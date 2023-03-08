/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:20:00 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/08 14:31:13 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	check_ac(int ac, char **av)
{
	if (ac <= 1)
	{
		ft_printf(R"Error\n"E);
		exit (ERROR);
	}
	else if (check_av(av) == ERROR)
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
		if (av[i][0] == '+' || av[i][0] == '-')
			j++;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				j++;
			else
				return (ERROR);
		}
		j = 0;
		i++;
	}
	return (SUCCES);
}

int	is_ordered(int ac, char **av)
{
	int *array;
	int	i;
	int	j;

	array = ft_calloc(sizeof(int), ac -1);
	if (!array)
		return (ERROR);
	i = 1;
	j = 0;
	while (av[i])
	{
		array[j] = ft_atoi(av[i]);
		j++;
		i++;
	}
	j = 0;
	while (j < ac - 1)
		ft_printf(B"%d"E, array[j++]);
	free(array);
	return (SUCCES);
}
