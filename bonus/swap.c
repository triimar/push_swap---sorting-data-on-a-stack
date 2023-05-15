/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:29:08 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/15 17:59:10 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stc **stack_a)
{
	t_stc	*tmp;

	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = (*stack_a)->next->next;
		tmp->next = (*stack_a);
		(*stack_a) = tmp;
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
}