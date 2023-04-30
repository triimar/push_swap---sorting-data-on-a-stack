/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:16:04 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/30 19:03:15 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stc **stack)
{
	t_stc	*tmp;

	if (stack)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			*stack = tmp;
		}
	}
}