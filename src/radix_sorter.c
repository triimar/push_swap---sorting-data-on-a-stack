/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:47:24 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/15 18:14:27 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

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

void	sort_by_bit(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf, int bit)
{
	int	j;

	j = -1;
	while (++j < s_inf->elements)
	{
		s_inf->curr_i = (*stc_a)->index;
		if ((s_inf->curr_i >> bit) & 1)
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
	return ;
}

void	radix_sorter(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	int	bits;
	int	i;

	i = -1;
	bits = (int)log2(s_inf->elements);
	while (++i <= bits)
	{
		sort_by_bit(stc_a, stc_b, s_inf, i);
		while (*stc_b)
			pa(stc_a, stc_b);
	}
}
