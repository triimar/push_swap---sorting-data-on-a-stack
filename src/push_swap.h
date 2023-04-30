/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:15:22 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/30 19:14:51 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stc
{
	int				val;
	int				index;
	struct s_stc	*next;	
}					t_stc;

typedef struct s_inf
{
	int		elements;	
}		t_inf;

/*   push_swap_errors.c   */
void	input_error(t_stc **stc_a, t_stc *new_node);
/*   push_swap_init.c   */
int		in_one_str(t_stc **stc_a, t_inf *s_inf, char *str);
int		create_stack(t_stc **stc_a, t_inf *s_inf, char **argv);
/*   push_swap_parsing.c   */
int		dup_check(t_stc **stack);
int		order_check(t_stc **stack);
/*   swap.c   */
void	sa(t_stc **stc_a);
void	sb(t_stc **stc_b);
void	ss(t_stc **stc_a, t_stc **stc_b);
/*   push.c   */
void	pa(t_stc **stc_a, t_stc **stc_b);
void	pb(t_stc **stc_a, t_stc **stc_b);
/*   rotate.c   */
void	ra(t_stc **stc_a);
void	rb(t_stc **stc_b);
void	rr(t_stc **stc_a, t_stc **stc_b);
/*   reverse_rotate.c   */
void	rra(t_stc **stc_a);
void	rrb(t_stc **stc_b);
void	rrr(t_stc **stc_a, t_stc **stc_b);
/*   push_swap_few.c   */
void	sort_few(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf);
/*   push_swap_utils.c   */
void	free_stack(t_stc **stack);
#endif