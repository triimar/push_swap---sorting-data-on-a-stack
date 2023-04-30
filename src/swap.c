/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:29:08 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/30 19:03:15 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// 1. sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

// 2. sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

// 3. ss : sa and sb at the same time.

void	sa(t_stc **stack_a)
{
	t_stc	*tmp;

	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = (*stack_a)->next->next;
		tmp->next = (*stack_a);
		(*stack_a) = tmp;
		ft_putendl_fd("sa", STDOUT_FILENO);
	}
}

void	sb(t_stc **stack_b)
{
	t_stc	*tmp;

	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = (*stack_b)->next->next;
		tmp->next = (*stack_b);
		(*stack_b) = tmp;
		ft_putendl_fd("sb", STDOUT_FILENO);
	}
}

void	ss(t_stc **stack_a, t_stc **stack_b)
{
	t_stc	*tmp;

	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = (*stack_a)->next->next;
		tmp->next = (*stack_a);
		(*stack_a) = tmp;
	}
	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = (*stack_b)->next->next;
		tmp->next = (*stack_b);
		(*stack_b) = tmp;
	}
	ft_putendl_fd("ss", STDOUT_FILENO);
}