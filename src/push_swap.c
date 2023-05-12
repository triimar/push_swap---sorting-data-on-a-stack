/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:55:38 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/13 00:20:19 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

static void	push_two_chunks(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	int	pushed;

	pushed = 0;
	while ((*stc_a))
	{	
		s_inf->curr_i = (*stc_a)->index;
		if (s_inf->curr_i > s_inf->min_i && s_inf->curr_i <= s_inf->max_i)
		{
			pb(stc_a, stc_b);
			if (s_inf->curr_i <= s_inf->max_i - s_inf->chunk_s)
				rb(stc_b);
			pushed++;
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
	s_inf->chunk_const = 11;
	s_inf->chunk_s = s_inf->elements / s_inf->chunk_const;
	s_inf->min_i = 0;
	s_inf->max_i = 2 * s_inf->chunk_s;
	while (*stc_a)
	{
		push_two_chunks(stc_a, stc_b, s_inf);
		s_inf->min_i = s_inf->max_i;
		s_inf->max_i = s_inf->max_i + 2 * s_inf->chunk_s;
	}	
}

void	sorter(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	int	pushed;
	int	remainder;
	int	head;
	int	start_i;

	remainder = s_inf->elements % s_inf->chunk_const;
	if (remainder)
		head = 1;
	s_inf->curr_i = s_inf->elements;
	start_i = s_inf->elements;
	
	pushed = 0;
	while (s_inf->curr_i > s_inf->elements - remainder - s_inf->chunk_s)
	{
		while ((*stc_b)->index > start_i - remainder - s_inf->chunk_s)
		{
			if ((*stc_b)->index != s_inf->curr_i \
				&& (*stc_b)->index != s_inf->curr_i - 1)
				rb(stc_b);
			else
			{
				pa(stc_a, stc_b);
				pushed++;
			}
		// 	remainder--;
		}
		rrb(stc_b);
		while ((*stc_b)->index > start_i - remainder - s_inf->chunk_s)
		{

			if ((*stc_b)->index == s_inf->curr_i \
				|| (*stc_b)->index == s_inf->curr_i - 1)
			{
				pa(stc_a, stc_b);
				pushed--;
			}
			else
				rrb(stc_b);
		}	
		if ((*stc_a)->next && (*stc_a)->index > (*stc_a)->next->index)
			sa(stc_a);
		s_inf->curr_i--;
	}
	// head = 0;
	// if (remainder)
	// 	head = 1;
	// s_inf->curr_i = s_inf->elements;
	// pushed = 0;
	// while (s_inf->curr_i >= s_inf->elements - 1)
	// {
	// 	while (head && remainder > 0)
	// 	{
	// 		if ((*stc_b)->index != s_inf->curr_i \
	// 			&& (*stc_b)->index != s_inf->curr_i - 1)
	// 			rb(stc_b);
	// 		else
	// 		{
	// 			pa(stc_a, stc_b);
	// 			pushed++;
	// 		}
	// 		remainder--;
	// 	}
	// 	if (remainder == 0)
	// 	{
	// 		head = 0;
	// 		remainder = s_inf->chunk_s;
	// 		ft_putendl_fd("swich to rrb", 1);
	// 	}
	// 	else
	// 	{
	// 		remainder = remainder - pushed;
	// 		pushed = 0;
	// 	}
	// 	while (!head && remainder > 0)
	// 	{
	// 		rrb(stc_b);
	// 		if ((*stc_b)->index == s_inf->curr_i \
	// 			|| (*stc_b)->index == s_inf->curr_i - 1)
	// 		{
	// 			pa(stc_a, stc_b);
	// 			pushed--;
	// 		}
	// 	}
	// 	if (remainder == 0)
	// 	{
	// 		ft_putendl_fd("swich to rb", 1);
	// 		head = 1;
	// 		remainder = s_inf->chunk_s;
	// 	}
	// 	if ((*stc_a)->next && (*stc_a)->index > (*stc_a)->next->index)
	// 		sa(stc_a);
	// 	s_inf->curr_i--;
	// }
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
