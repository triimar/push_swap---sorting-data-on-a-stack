/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:29:54 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/28 17:16:06 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// 1. ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

// 2. rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

// 3. rr : ra and rb at the same time.

void	ra(t_stack **stack_a)
{
	t_stack	*new_tail;
	t_stack	*flip;

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

void	rb(t_stack **stack_b)
{
	t_stack	*new_tail;
	t_stack	*flip;

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

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_tail;
	t_stack	*flip;

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