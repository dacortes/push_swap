/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:30:05 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/19 10:33:49 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

int	the_size_is_three(t_stack *a)
{
	int	index;

	index = 1;
	while (index != a->top->index)
		reverse_rotate(a, REV_ROTATE_A);
	if (is_stack_sorted(a, AS))
		return (SUCCESS);
	swap(a, SWAP_A);
	rotate(a, ROTATE_A);
	return (SUCCESS);
}
