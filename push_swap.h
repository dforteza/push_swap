/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: difortez <difortez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 16:23:56 by difortez          #+#    #+#             */
/*   Updated: 2026/09/29 18:06:14 by difortez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define NONE -1
# define SIMPLE 0
# define MEDIUM 1
# define COMPLEX 2
# define ADAPTIVE 3
# define LINEAR 4
# define SMALL 5

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define N_OPS 11

# define BOTTOM 0
# define TOP 1

# include "libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_ps
{
	t_node			*a;
	t_node			*b;
	int				strategy;
	int				used;
	int				bench;
	int				count[N_OPS];
	double			disorder;
}					t_ps;

typedef struct s_part
{
	char			stack;
	int				pos;
	int				size;
}					t_part;

// OPERATIONS
void				sa(t_ps *ps);
void				sb(t_ps *ps);
void				ss(t_ps *ps);

void				pa(t_ps *ps);
void				pb(t_ps *ps);

void				ra(t_ps *ps);
void				rb(t_ps *ps);
void				rr(t_ps *ps);

void				rra(t_ps *ps);
void				rrb(t_ps *ps);
void				rrr(t_ps *ps);

// OPS UTILS
void				log_op(t_ps *ps, char *name, int op);

// SORT UTILS
void				move_to_top(t_ps *ps, char name, int p);

// SELECTION SORT (--simple)
void				selection_sort(t_ps *ps);

// CHUNK SORT (--medium)
void				chunk_sort(t_ps *ps);

// SMALL SORT (5 o menos)
void				small_sort(t_ps *ps);

// RADIX SORT (--complex)
void				radix_sort(t_ps *ps);

// QUICKSORT (--complex)
void				quick_sort(t_ps *ps);

// FLAGS
int					parse_flags(t_ps *ps, int ac, char **av);

// STACK
int					is_sorted(t_node *stack);
int					has_two(t_node *stack);
int					find_size(t_node *stack);
int					find_min(t_node *stack, int size);
int					find_max(t_node *stack);
int					find_place(t_node *stack, int n);
t_node				*find_last(t_node *stack);

// PARSING
void				parse_numbers(t_ps *ps, int ac, char **av, int i);

// ERRORS
void				free_split(char **nums);
void				free_stack(t_node *stack);
void				error_exit(t_ps *ps, char **nums);

// NORMALIZE
void				normalize(t_node *a);

// DISORDER
double				calculate_disorder(t_node *a);

// BENCH
void				print_bench(t_ps *ps);

#endif
