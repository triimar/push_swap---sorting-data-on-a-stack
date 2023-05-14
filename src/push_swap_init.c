/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:03:39 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/14 21:16:04 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	*stc_a = NULL;
	*stc_b = NULL;
	s_inf->elements = 0;
	s_inf->node_i = -1;
	s_inf->chunk_const = 1;
	s_inf->chunk_s = 0;
	s_inf->curr_i = 0;
	s_inf->min_i = 0;
	s_inf->max_i = 0;
	s_inf->next_pushed = 0;
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

void	init_sorting(t_inf *s_inf)
{
	if (s_inf->elements >= 6 && s_inf->elements < 90)
		s_inf->chunk_const = 5;
	if (s_inf->elements >= 90 && s_inf->elements < 280)
		s_inf->chunk_const = 11;
	if (s_inf->elements >= 280)
		s_inf->chunk_const = 19;
	s_inf->chunk_s = s_inf->elements / s_inf->chunk_const;
	s_inf->max_i = 2 * s_inf->chunk_s;
}
