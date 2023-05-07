/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_few.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:11:42 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/07 20:07:54 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_check(t_stc **stack)
{
	t_stc	*checker;

	checker = *stack;
	while (checker->next)
	{
		if (checker->val > checker->next->val)
			return (0);
		checker = checker->next;
	}
	return (1);
}

static void	sort_three(t_stc **stc_a)
{
	t_stc	*a;

	a = *stc_a;

	while (!(order_check(stc_a)))
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

static void	rotate_four_five(t_stc **stc_a)
{
	if ((*stc_a)->index >= 3 && (*stc_a)->next->index >= 3 \
		&& (*stc_a)->next->next->index >= 3)
		rra(stc_a);
	while ((*stc_a)->index >= 3)
		ra(stc_a);
}

static void	sort_four_five(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	rotate_four_five(stc_a);
	if (order_check(stc_a))
		return ;
	if (s_inf->elements == 5)
	{
		pb(stc_a, stc_b);
		rotate_four_five(stc_a);
	}
	if (!order_check(&(*stc_a)->next))
	{
		pb(stc_a, stc_b);
		sort_three(stc_a);
		pa(stc_a, stc_b);
	}
	if ((*stc_a)->index > (*stc_a)->next->index)
		sa(stc_a);
	if (s_inf->elements == 5)
	{
		pa(stc_a, stc_b);
		if ((*stc_a)->index > (*stc_a)->next->index)
			sa(stc_a);
	}
}

void	sort_few(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	if (s_inf->elements == 2)
		sa(stc_a);
	else if (s_inf->elements == 3)
		sort_three(stc_a);
	else if (s_inf->elements == 4 || s_inf->elements == 5)
		sort_four_five(stc_a, stc_b, s_inf);
	return ;
}
