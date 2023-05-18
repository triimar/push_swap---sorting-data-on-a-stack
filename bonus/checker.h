/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:15:22 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/15 22:25:51 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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
	int		node_i;
}			t_inf;

/*   checker_init.c   */
void	init_data(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf);
void	init_sorting(t_inf *s_inf);
void	ft_indexer(t_stc **stc_a, t_inf *inf, t_stc *tail, t_stc *new);
/*   checker_parsing.c   */
int		one_str_input(t_stc **stc_a, t_inf *s_inf, char *str);
int		create_stack(t_stc **stc_a, t_inf *s_inf, char **argv);
/*   checker.c   */
void	checker(t_stc **stc_a, t_stc **stc_b);
/*_____________________________________________________________________*/
/*   checker_errors.c   */
void	input_error(t_stc **stc_a, t_stc *new_node);
void	instruction_error(t_stc **stc_a, t_stc **stc_b);
/*   checker_utils.c   */
int		order_check(t_stc **stack);
int		is_valid_input(char *str);
t_stc	*get_tail(t_stc **stack);
char	*ft_free_pp(char **p_p);
void	free_stacks(t_stc **stc_a, t_stc **stc_b);
/*____________________________________________________________________*/
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

#endif