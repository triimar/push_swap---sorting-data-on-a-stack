/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:55:38 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/14 01:05:24 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

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
				rb(stc_b);
		}
		else
			ra(stc_a);
		if (s_inf->max_i + s_inf->chunk_s <= s_inf->elements \
		&& pushed == s_inf->max_i - s_inf->min_i)
			return ;
	}
	return ;
}

void	pre_sorter(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	if (s_inf->elements >= 6 && s_inf->elements < 90)
		s_inf->chunk_const = 5;
	if (s_inf->elements >= 90 && s_inf->elements < 280)
		s_inf->chunk_const = 11;
	if (s_inf->elements >= 280)
		s_inf->chunk_const = 17;
	s_inf->chunk_s = s_inf->elements / s_inf->chunk_const;
	s_inf->min_i = 0;
	s_inf->max_i = 2 * s_inf->chunk_s;
	while (*stc_a)
	{
		// ft_putnbr_fd(s_inf->min_i, 1);
		// ft_putstr_fd(" - min_i | ", 1);
		// ft_putnbr_fd(s_inf->max_i, 1);
		// ft_putendl_fd(" -  max_i", 1);
		push_two_chunks(stc_a, stc_b, s_inf);
		s_inf->min_i = s_inf->max_i;
		s_inf->max_i = s_inf->max_i + 2 * s_inf->chunk_s;
		if (s_inf->max_i > s_inf->elements)
			s_inf->max_i = s_inf->elements;
	}	
}

int	is_on_top(t_stc **stack, t_inf *s_inf, int next)
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

void	sorter(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	int	next_pushed;

	next_pushed = 0;
	s_inf->curr_i = s_inf->elements;
	while (*stc_b || s_inf->curr_i > 0)
	{
		if (is_on_top(stc_b, s_inf, s_inf->curr_i))
		{
			while (*stc_b && (*stc_b)->index != s_inf->curr_i)
			{
				if ((*stc_b)->index == s_inf->curr_i - 1)
				{
					pa(stc_a, stc_b);
					next_pushed = 1;
				}
				if ((*stc_b)->index != s_inf->curr_i)
					rb(stc_b);
			}
		}
		else
		{
			while ((*stc_b) && (*stc_b)->index != s_inf->curr_i)
			{
				if ((*stc_b)->index == s_inf->curr_i - 1)
				{
					pa(stc_a, stc_b);
					next_pushed = 1;
				}
				if ((*stc_b)->index != s_inf->curr_i)
					rrb(stc_b);
			}
		}
		pa(stc_a, stc_b);
		s_inf->curr_i = s_inf->curr_i - next_pushed - 1;
		next_pushed = 0;
		if ((*stc_a)->next && (*stc_a)->index > (*stc_a)->next->index)
			sa(stc_a);
	}	
	return ;
}

static int	index_in_order(t_stc **stack)
{
	t_stc	*checker;

	checker = *stack;
	while (checker->next)
	{
		if (checker->val + 1 != checker->next->val)
			return (0);
		checker = checker->next;
	}
	return (1);
}

void	radix_sorter(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	int	bits;
	int	i;
	int	j;

	i = -1;
	bits = (int)log2(s_inf->elements);
	while (++i <= bits)
	{
		j = -1;
		while (++j < s_inf->elements)
		{
			s_inf->curr_i = (*stc_a)->index;
			if ((s_inf->curr_i >> i) & 1)
				ra(stc_a);
			else
				pb(stc_a, stc_b);
			if (index_in_order(stc_a))
			{
				if (!(*stc_b))
					return ;
				break ;
			}
		}
		while (*stc_b)
			pa(stc_a, stc_b);
	}
}
