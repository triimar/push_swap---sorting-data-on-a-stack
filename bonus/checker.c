/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:05:19 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/15 20:36:18 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 == 0 || s2 == 0)
		return (0);
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != '\0' || *s2 != '\0')
		return (0);
	return (1);
}

static void	execute_move(t_stc **stc_a, t_stc **stc_b, char *move)
{
	if (ft_strcmp(move, "pa\n"))
		pa(stc_a, stc_b);
	else if (ft_strcmp(move, "pb\n"))
		pb(stc_a, stc_b);
	else if (ft_strcmp(move, "sa\n"))
		sa(stc_a);
	else if (ft_strcmp(move, "sb\n"))
		sb(stc_b);
	else if (ft_strcmp(move, "ss\n"))
		ss(stc_a, stc_b);
	else if (ft_strcmp(move, "ra\n"))
		ra(stc_a);
	else if (ft_strcmp(move, "rb\n"))
		rb(stc_b);
	else if (ft_strcmp(move, "rr\n"))
		rr(stc_a, stc_b);
	else if (ft_strcmp(move, "rra\n"))
		rra(stc_a);
	else if (ft_strcmp(move, "rrb\n"))
		rrb(stc_b);
	else if (ft_strcmp(move, "rrr\n"))
		rrr(stc_a, stc_b);
	else
		instruction_error(stc_a, stc_b);
	return ;
}

void	checker(t_stc **stc_a, t_stc **stc_b)
{
	char	*move;

	move = get_next_line(STDIN_FILENO);
	while (move)
	{
		execute_move(stc_a, stc_b, move);
		free(move);
		move = get_next_line(STDIN_FILENO);
	}
	if (order_check(stc_a) && !(*stc_b))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	return ;
}
