/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:29:54 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/15 22:02:20 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stc **stack_a)
{
	t_stc	*new_tail;
	t_stc	*flip;

	if ((*stack_a) && (*stack_a)->next)
	{
		new_tail = *stack_a;
		*stack_a = (*stack_a)->next;
		flip = *stack_a;
		while (flip->next)
			flip = flip->next;
		flip->next = new_tail;
		new_tail->next = NULL;
		ft_putendl_fd("ra", STDOUT_FILENO);
	}
}

void	rb(t_stc **stack_b)
{
	t_stc	*new_tail;
	t_stc	*flip;

	if ((*stack_b) && (*stack_b)->next)
	{
		new_tail = *stack_b;
		*stack_b = (*stack_b)->next;
		flip = *stack_b;
		while (flip->next)
			flip = flip->next;
		flip->next = new_tail;
		new_tail->next = NULL;
		ft_putendl_fd("rb", STDOUT_FILENO);
	}
}

void	rr(t_stc **stack_a, t_stc **stack_b)
{
	t_stc	*new_tail;
	t_stc	*flip;

	if ((*stack_a) && (*stack_a)->next)
	{
		new_tail = *stack_a;
		*stack_a = (*stack_a)->next;
		flip = *stack_a;
		while (flip->next)
			flip = flip->next;
		flip->next = new_tail;
		new_tail->next = NULL;
	}
	if ((*stack_b) && (*stack_b)->next)
	{
		new_tail = *stack_b;
		*stack_b = (*stack_b)->next;
		flip = *stack_b;
		while (flip->next)
			flip = flip->next;
		flip->next = new_tail;
		new_tail->next = NULL;
	}
	if (((*stack_a) && (*stack_a)->next) || ((*stack_b) && (*stack_b)->next))
		ft_putendl_fd("rr", STDOUT_FILENO);
}
