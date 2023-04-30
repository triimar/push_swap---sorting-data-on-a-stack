/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_few.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:11:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/30 23:36:28 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_stc **stc_a)
{
	t_stc	*checker;

	checker = *stc_a;
	while (checker->next)
	{
		if (checker->val > checker->next->val)
			return (0);
		checker = checker->next;
	}
	return (1);
}

void	sort_three(t_stc **stc_a)
{
	t_stc	*a;

	a = *stc_a;
	while (!(is_ordered(stc_a)))
	{
		if (a->next->val > a->val && a->val > a->next->next->val)
			rra(stc_a);
		else if (a->val > a->next->next->val && \
			a->next->next->val > a->next->val)
			ra(stc_a);
		else
			sa(stc_a);
		a = *stc_a;
	}
}

void	sort_few(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	// int		i;
	// t_stc	*a;
	// t_stc	*b;

	// i = 0;
	t_stc	*tail;
	
	if (s_inf->elements == 2)
		sa(stc_a);
	else if (s_inf->elements == 3)
		sort_three(stc_a);
	else if (s_inf->elements == 4)
	{
		while (!is_ordered(stc_a))
		{	
			tail = *stc_a;
			while (tail->next)
				tail = tail->next;
			if ((*stc_a)->val > tail->val)
				ra(stc_a);
			if ((*stc_a)->val > (*stc_a)->next->val)
				sa(stc_a);
			if (is_ordered(stc_a))
				break ;
			pb(stc_a, stc_b);
			sort_three(stc_a);
			pa(stc_a, stc_b);
		}
	}
	// else
	// {		
	// 	while (!is_ordered(stc_a))
	// 	{
	// 		if ((*stc_a)->val > (*stc_a)->next->val)
	// 			sa(stc_a);
	// 		if (is_ordered(stc_a))
	// 			break ;
	// 		// while ((i++) + 3 < s_inf->elements)
	// 		// {
	// 			pb(stc_a, stc_b);
	// 		// 	if ((*stc_a)->val > (*stc_a)->next->val)
	// 		// 		sa(stc_a);
	// 		// }
	// 		sort_three(stc_a);
	// 		// if ((*stc_b)->next && (*stc_b)->val < (*stc_b)->next->val)
	// 		// 	sb(stc_b);
	// 		pa(stc_a, stc_b);
	// 		tail = *stc_a;
	// 		while (tail->next)
	// 			tail = tail->next;
	// 		if ((*stc_a)->val > tail->val)
	// 			ra(stc_a);
	// 		// i--;
	// 		// if (stc_b && is_ordered(stc_a))
	// 		// {
	// 		// 	pa(stc_a, stc_b);
	// 		// 	i--;
	// 		// }
	// 	}
	// }
	return ;
}
