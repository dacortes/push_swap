/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:20:00 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/10 12:07:12 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	check_ac(int ac, char **av)
{
	if (ac <= 1)
		exit (ERROR);
	else if (check_av(av) == ERROR || check_num(ac, av)/*check_num_neg(ac,av) == ERROR
		||  check_num_pos(ac,av) == ERROR*/)
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

int	check_num(int ac, char **av)
{
	{
	int	i;
	int	size;

	i = 1;
	while (i < ac)
	{
		size = ft_strlen(av[i]);
		if (size == 0 || ((size > 10 && av[i][0] != '-') || 
			(size > 10 && av[i][0] != '+')) || size > 11)
		{
			ft_printf("hola");
			return (ERROR);
		}
		if (av[i][0] != '-' && size == 10 &&
			ft_strncmp(av[i], "2147483647", 10) > 0)
			return (ERROR);
		if (av[i][0] == '-' && size == 11 &&
			ft_strncmp(av[i], "-2147483648", 11) > 0)
			return (ERROR);
		if (av[i][0] == '+' && size == 11 &&
			ft_strncmp(av[i], "+2147483648", 11) > 0)
			return (ERROR);
		++i;
	}
	return (SUCCES);
}
}
/*int	check_num_neg(int ac, char **av)
{
	int	i;
	int	size;

	i = 1;
	while (i < ac)
	{
		size = ft_strlen(av[i]);
		if ((ft_strncmp(av[i], "-2147483648", 11) > 0 && size == 11) || size == 0)
		{
			ft_printf(R"%s\n"E, av[i]);
			ft_printf(B"%d\n"E, ft_strncmp(av[i], "-2147483648", 11));
			ft_printf(Y"%d\n"E, size);
			return (ERROR);
		}
		i++;
	}
	return (SUCCES);
}

int	check_num_pos(int ac, char **av)
{
	int	i;
	int	size;

	i = 1;
	while (i < ac)
	{
		size = ft_strlen(av[i]);
		if ((ft_strncmp(av[i], "2147483647", 10) > 0 && size >= 10) || size == 0)
		{
			ft_printf(B"%d\n"E,ft_strncmp(av[i], "2147483647", 10));
			return (ERROR);
		}
		if (((ft_strncmp(av[i], "+2147483647", 11) > 0 && size == 11)
			&& check_num_neg(ac,av) == SUCCES) || size == 0)
		{
			ft_printf(R"%s\n"E, av[i]);
			ft_printf(B"%d\n"E, ft_strncmp(av[i], "+2147483648", 11));
			ft_printf(Y"%d\n"E, size);
			return (ERROR);
		}
		i++;
	}
	return (SUCCES);
}*/
/*int	is_ordered(int ac, char **av)
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
	while (j < ac -1)
		ft_printf(B"%d "E, array[j++]);
	ft_printf("\n");
	j = 0;
	i = 0;
	while (array[j] && j <= ac - 1)
	{
		while (array[i] && i <= ac -1)
		{
			if (array[j] > array[i])
				ft_printf(G"OK"E);
			else if (array[j] == array[i + 1])
				{
					ft_printf(R"Es igual no puedo trabajar\n"E);
					free(array);
					return (ERROR);
				}
			i++;
		}
		i = j + 1;
		j++;
	}
	free(array);
	return (SUCCES);
}*/
