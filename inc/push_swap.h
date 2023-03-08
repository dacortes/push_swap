/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:04:08 by dacortes          #+#    #+#             */
/*   Updated: 2023/03/08 13:37:04 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include"../libft/libft.h"
# include"../libft/ft_printf.h"

// ================================= MACROS ================================= //

/* Outputs */
# define SUCCES 0
# define FALSE 0
# define TRUE 1
# define ERROR -1
# define E_EXIT 1

/* Options */
# define SWAP_A			1
# define SWAP_B			2
# define SWAP			3
# define PUSH_A			1
# define PUSH_B			2
# define ROTATE_A		1
# define ROTATE_B		2
# define ROTATE			3
# define REV_ROTATE_A	1
# define REV_ROTATE_B	2
# define REV_ROTATE		3

// ================================= COLORS ================================= //

# define E "\033[m"        //end
# define R "\033[1;31m"    //red
# define G "\033[1;32m"    //green
# define Y "\033[1;33m"    //yellow
# define B "\033[1;34m"    //blue

// ================================= STRUCTURES ============================= //

/* auxiliary node*/
typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* main stack structure */
typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bot;
}	t_stack;

// ================================= FUNCTIONS ============================== //

/* check/check_arg */
int		check_ac(int ac, char **av);
int		check_av(char **av);
/* src/destroy/destroy.c */
void	stack_destroy(t_stack *stack);
/* src/init/init.c */
int		stack_init(t_stack **stack);
/* intructions/push.c */
int		push_stack(t_stack *stack, int num);

#endif