/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:48:29 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/30 19:03:15 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_error(t_stc **stack_a, t_stc *new_node)
{	
	if (new_node)
		free(new_node);
	if (*stack_a)
		free_stack(stack_a);
	ft_putendl_fd("Error", 1);
	exit(EXIT_FAILURE);
}
