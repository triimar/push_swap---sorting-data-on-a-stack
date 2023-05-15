/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:29:08 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/15 22:02:42 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
