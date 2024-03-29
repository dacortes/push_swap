/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:30:05 by dacortes          #+#    #+#             */
/*   Updated: 2023/05/02 12:45:29 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	the_size_is_three(t_stack *a)
{
	while (!is_stack_sorted(a, AS))
	{
		if (find_num(a, 1) == 3 && find_num(a, 3) != 1)
			reverse_rotate(a, STACK_A);
		else if (find_num(a, 1) == 2 && find_num(a, 3) != 1)
			swap(a, STACK_A);
		else if (find_num(a, 3) == 1 && find_num(a, 1) != 2)
			swap(a, STACK_A);
		else if (find_num(a, 3) == 1 && find_num(a, 1) == 2)
			rotate(a, STACK_A);
		else if (find_num(a, 3) == 2 && find_num(a, 1) == 1)
			reverse_rotate(a, STACK_A);
		else if (find_num(a, 3) == 1 && find_num(a, 1) == 3)
			rotate(a, STACK_A);
	}
	return (SUCCESS);
}
