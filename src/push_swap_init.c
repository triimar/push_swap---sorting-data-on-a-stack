/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:03:39 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/07 21:26:54 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initiate_data(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	*stc_a = NULL;
	*stc_b = NULL;
	s_inf->node_i = -1;
}

void	ft_indexer(t_stc **stc_a, t_inf *inf, t_stc *tail, t_stc *new)
{
	t_stc	*modifier;

	if (!(*stc_a))
		new->index = 1;
	else if (tail && new->val > tail->val && tail->index == inf->node_i)
		new->index = tail->index + 1;
	else
	{
		modifier = *stc_a;
		new->index = 1;
		while (modifier)
		{
			if (new->val == modifier->val)
				input_error(stc_a, new);
			if (new->val > modifier->val)
				new->index++;
			else if (new->val < modifier->val)
				modifier->index++;
			modifier = modifier->next;
		}
	}
}