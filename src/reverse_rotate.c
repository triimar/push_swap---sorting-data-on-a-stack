/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:30:35 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/28 17:36:57 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

// 2. rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

// 3. rrr : rra and rrb at the same time.

void	rra(t_stack **stack_a)
{
	t_stack	*flip;
	t_stack	*new_head;

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

void	rrb(t_stack **stack_b)
{
	t_stack	*flip;
	t_stack	*new_head;

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

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*flip;
	t_stack	*new_head;

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
