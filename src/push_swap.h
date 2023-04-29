/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:15:22 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/29 21:06:54 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;	
}					t_stack;

typedef struct s_inf
{
	int		elements;	
	t_stack	*tail;
}		t_inf;

/*   push_swap_errors.c   */
void	input_error(t_stack **stack_a);
/*   push_swap_parsing.c   */
int		in_one_str(t_stack **stack_a, t_inf *s_inf, char *str);
int		create_stack(t_stack **stack_a, t_inf *s_inf, char **argv);
/*   swap.c   */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
/*   push.c   */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
/*   rotate.c   */
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
/*   reverse_rotate.c   */
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
/*   push_swap_utils.c   */
void	free_stack(t_stack **stack);
#endif