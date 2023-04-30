/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:48:52 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/30 19:03:15 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_check(t_stc **stack)
{
	t_stc	*current;
	t_stc	*flip;
	int		i;
	int		j;

	current = (*stack)->next;
	i = 1;
	while (current)
	{
		flip = *stack;
		j = 0;
		while (j < i)
		{
			if (flip->val == current->val)
				return (1);
			flip = flip->next;
			j++;
		}	
		current = current->next;
		i++;
	}
	return (0);
}

int	order_check(t_stc **stack)
{
	t_stc	*current;
	t_stc	*flip;

	current = (*stack)->next;
	flip = *stack;
	while (current)
	{
		if (current->val < flip->val)
			return (0);
		else
		{
			current = current->next;
			flip = flip->next;
		}
	}
	return (1);
}
