/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:28:28 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/13 23:46:15 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stc **stack_a, t_stc **stack_b)
{
	t_stc	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		if (!(*stack_a))
		{
			*stack_a = tmp;
			(*stack_a)->next = NULL;
		}
		else
		{
			tmp->next = *stack_a;
			*stack_a = tmp;
		}
		ft_putendl_fd("pa", STDOUT_FILENO);
	}
}

void	pb(t_stc **stack_a, t_stc **stack_b)
{
	t_stc	*tmp;

	if (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		if (!(*stack_b))
		{
			*stack_b = tmp;
			(*stack_b)->next = NULL;
		}
		else
		{
			tmp->next = *stack_b;
			*stack_b = tmp;
		}
		ft_putendl_fd("pb", STDOUT_FILENO);
	}
}
