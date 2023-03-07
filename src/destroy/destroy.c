/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:25:09 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/07 16:29:24 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../inc/push_swap.h"

void	stack_destroy(t_stack *destroy)
{
	t_element	*elem;

	while (destroy->top != NULL)
	{
		elem = destroy->top;
		destroy->top = destroy->top->next;
		free(elem);
	}
	free(destroy);
}
