/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:30:35 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/15 22:02:54 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stc **stack_a)
{
	t_stc	*flip;
	t_stc	*new_head;

	if ((*stack_a) && (*stack_a)->next)
	{
		flip = (*stack_a);
		while (flip->next->next)
			flip = flip->next;
		new_head = flip->next;
		flip->next = NULL;
		new_head->next = *stack_a;
		*stack_a = new_head;
		ft_putendl_fd("rra", STDOUT_FILENO);
	}
}

void	rrb(t_stc **stack_b)
{
	t_stc	*flip;
	t_stc	*new_head;

	if ((*stack_b) && (*stack_b)->next)
	{
		flip = (*stack_b);
		while (flip->next->next)
			flip = flip->next;
		new_head = flip->next;
		flip->next = NULL;
		new_head->next = *stack_b;
		*stack_b = new_head;
		ft_putendl_fd("rrb", STDOUT_FILENO);
	}
}

void	rrr(t_stc **stack_a, t_stc **stack_b)
{
	t_stc	*flip;
	t_stc	*new_head;

	if ((*stack_a) && (*stack_a)->next)
	{
		flip = (*stack_a);
		while (flip->next->next)
			flip = flip->next;
		new_head = flip->next;
		flip->next = NULL;
		new_head->next = *stack_a;
		*stack_a = new_head;
	}
	if ((*stack_b) && (*stack_b)->next)
	{
		flip = (*stack_b);
		while (flip->next->next)
			flip = flip->next;
		new_head = flip->next;
		flip->next = NULL;
		new_head->next = *stack_b;
		*stack_b = new_head;
	}
	if (((*stack_a) && (*stack_a)->next) || ((*stack_b) && (*stack_b)->next))
		ft_putendl_fd("rrr", STDOUT_FILENO);
}
