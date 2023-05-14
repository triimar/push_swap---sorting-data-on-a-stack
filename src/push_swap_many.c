/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_many.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:55:38 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/14 18:52:00 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_two_chunks(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	int	pushed;

	pushed = 0;
	while ((pushed < s_inf->max_i - s_inf->min_i))
	{	
		s_inf->curr_i = (*stc_a)->index;
		if (s_inf->curr_i > s_inf->min_i && s_inf->curr_i <= s_inf->max_i)
		{
			pb(stc_a, stc_b);
			pushed++;
			if (s_inf->curr_i <= s_inf->max_i - s_inf->chunk_s)
			{
				if (*stc_a && ((*stc_a)->index <= s_inf->min_i \
								|| (*stc_a)->index > s_inf->max_i))
					rr(stc_a, stc_b);
				else
					rb(stc_b);
			}
		}
		else
			ra(stc_a);
	}
	return ;
}

static void	sort_to_b(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	while (*stc_a)
	{
		push_two_chunks(stc_a, stc_b, s_inf);
		s_inf->min_i = s_inf->max_i;
		s_inf->max_i = s_inf->max_i + 2 * s_inf->chunk_s;
		if (s_inf->max_i > s_inf->elements)
			s_inf->max_i = s_inf->elements;
	}	
}

static int	is_on_top(t_stc **stack, t_inf *s_inf, int next)
{
	t_stc	*checked;
	int		i;

	checked = *stack;
	i = 0;
	while (checked && i <= s_inf->chunk_s)
	{
		if (checked->index == next)
			return (1);
		checked = checked->next;
		i++;
	}
	return (0);
}

static void	find_next(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf, int i)
{
	while (*stc_b && (*stc_b)->index != s_inf->curr_i)
	{
		if ((*stc_b)->index == s_inf->curr_i - 1)
		{
			pa(stc_a, stc_b);
			s_inf->next_pushed = 1;
		}
		if ((*stc_b)->index != s_inf->curr_i && i == 0)
			rb(stc_b);
		else if ((*stc_b)->index != s_inf->curr_i && i == 1)
			rrb(stc_b);
	}
}

void	sort_many(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	sort_to_b(stc_a, stc_b, s_inf);
	s_inf->curr_i = s_inf->elements;
	while (*stc_b || s_inf->curr_i > 0)
	{
		if (is_on_top(stc_b, s_inf, s_inf->curr_i))
			find_next(stc_a, stc_b, s_inf, 0);
		else
			find_next(stc_a, stc_b, s_inf, 1);
		pa(stc_a, stc_b);
		if ((*stc_a)->next && (*stc_a)->index > (*stc_a)->next->index)
		{
			if (*stc_b && (*stc_b)->next && \
			(*stc_b)->index < (*stc_b)->next->index)
				ss(stc_a, stc_b);
			else
				sa(stc_a);
		}
		s_inf->curr_i = s_inf->curr_i - s_inf->next_pushed - 1;
		s_inf->next_pushed = 0;
	}	
	return ;
}
