/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:34:05 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/14 12:38:49 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"
# include "../src/printf2/inc/ft_printf.h"
# include <stdlib.h>
# include "../src_bonus/gnl/get_next_line.h"

typedef struct s_stack
{
	int	content;
	int	index;
	int	pos;
	int	active;
}		t_stack;

# define EMPTY 0
# define R 1
# define Rr 2
# define P 3
# define S 4

# define A 10
# define B 20

# define RA 11
# define RB 21
# define RR 31
# define RRA 12
# define RRB 22
# define RRR 32
# define PA 13
# define PB 23
# define SA 14
# define SB 24
# define SS 34

//prints out t_stack
void	ft_prnt_lst(t_stack *stack, int argc);
//prints out t_list
void	ft_lst_prnt(t_list *stack);
t_stack	*ft_init(int argc, char *argv[]);
t_stack	*ft_init_empty(int amount);
void	indexer(t_stack *stack[], int amount);

void	exec(int action, t_list *actions[], t_stack *stack_a[],
			t_stack *stack_b[]);
void	exec_a_only(int action, t_list *actions[], t_stack *stack_a[]);
void	exec_b_only(int action, t_list *actions[], t_stack *stack_b[]);
void	exec_empty(int action, t_list *actions[], t_stack *stack[]);

void	print_instructions(t_list *actions);
const char	*get_macro_name(int value);

int		rotate(t_stack *stack[]);
int		rrotate(t_stack *stack[]);
int		swap(t_stack *stack[]);
int		push(t_stack *sender[], t_stack *receiver[]);

t_stack	*last_active(t_stack stack[]);
int	highest_index(t_stack stack[]);
int	lowest_index(t_stack stack[]);

//error checks
int	error_check(int amount, t_stack *stack, char *argv[]);

//algo start
void	hardcode(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[]);

int		master(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[]);
void	orient(t_stack *stack[], int option, t_list *actions[]);
void	update_new_actions(t_list *new_actions[], int option);
int	is_unsorted(t_stack stack[]);
int	is_in_lower(t_stack stack_a[]);
int	is_in_upper(t_stack stack_a[]);
void	rotate_push_start(t_stack *stack_a[],t_stack *stack_b[], t_list *actions[]);
void	rotate_swap(t_stack *stack[], t_list *actions[], int option);
int	quick_sort(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[]);

int	high_enough(t_stack *stack);
int	low_enough(t_stack *stack);
int is_done(t_stack *stack_a[]);

void	optimize(t_list **actions);
void	optimize_5(t_list *actions[]);
void	remove_next_2(t_list **pre);
void	hardcode_5(t_stack *stack_a[], t_stack *stack_b[], t_list *actions[]);
void	hardcode_3(t_stack *stack_a[], t_list *actions[]);
#endif
