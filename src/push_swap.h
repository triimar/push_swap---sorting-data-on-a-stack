/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:15:22 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/23 22:39:26 by tmarts           ###   ########.fr       */
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
	unsigned int	index;	
}					t_stack;

typedef struct s_inf
{
	int	elements;	
}		t_inf;

/*   push_swap_errors.c   */
void	input_error(char *str);
/*   push_swap_parsing.c   */
int		create_stack(t_stack **stack_a, t_inf *s_inf, char **argv);
/*   swap.c   */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
/*   rotate.c   */
/*   reverse_rotate.c   */
/*   push.c   */

#endif