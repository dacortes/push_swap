/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:04:08 by dacortes          #+#    #+#             */
/*   Updated: 2023/04/13 14:54:28 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include"../libft/libft.h"
# include"../libft/ft_printf.h"

// ================================= MACROS ================================= //

/* Outputs */
# define SUCCESS 0
# define FALSE	 0
# define TRUE	 1
# define ERROR 	-1
# define E_EXIT  1

/* Options */
# define NEXT_			1
# define PREV_			2
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

/* auxiliary structure */
typedef struct s_axu
{
	int	num;
	int	next;
	int	min_index;
	int	*data;
	int	*index;
}	t_aux;

/* auxiliary node*/
typedef struct s_node
{
	int				data;
	int				index;
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
int		check_arg(int ac, char **av);
int		check_av(char **av);
int		check_num(int ac, char **av);
int		check_duplicate(int ac, char **av);
int		is_stack_sorted(t_stack *stack);
/* src/destroy/destroy.c */
void	stack_destroy(t_stack *stack);
void	double_destroy(t_stack *one, t_stack *two);
/* src/init/init.c */
int		double_init(t_stack **one, t_stack **two);
/* intructions/push.c */
int		push_stack(t_stack *stack, int data, int index);
int		pop_stack(t_stack *stack);
int		push(t_stack *scr, t_stack *dst, int type_push);
/* intructions/reverse_rotate.c */
int		reverse_rotate(t_stack *stack, int type_reverse_rotate);
int		double_rrr(t_stack *one, t_stack *two, int type_reverse_rotate);
/* instructions/rotate */
int		rotate(t_stack *stack, int type_rotate);
int		rotate_rotate(t_stack *one, t_stack *two, int type_rotate);
/* intructions/swap */
int		swap(t_stack *stack, int type_swap);
int		swap_swap(t_stack *stack_one, t_stack *stack_tow);
/* utils.c */
void	stack_printf(t_stack	*sactk);
void	node_printf(t_node	*node, int type);
#endif