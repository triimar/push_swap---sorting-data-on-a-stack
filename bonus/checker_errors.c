/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:48:29 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/15 18:11:26 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	input_error(t_stc **stack_a, t_stc *new_node)
{	
	if (new_node)
		free(new_node);
	if (stack_a && *stack_a)
		free_stacks(stack_a, NULL);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	instruction_error(t_stc **stc_a, t_stc **stc_b)
{
	free_stacks(stc_a, stc_b);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
