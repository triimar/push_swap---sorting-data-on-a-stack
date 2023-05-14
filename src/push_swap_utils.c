/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:16:04 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/14 18:03:01 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_input(char *str)
{
	char	*check;

	check = str;
	if (!(*str))
		return (1);
	if (check && (*check == '-' || *check == '+') && *(check + 1) != '\0')
		check++;
	while (*check != '\0')
	{
		if (!(*check >= '0' && *check <= '9'))
			return (0);
		check++;
	}
	return (1);
}

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

t_stc	*get_tail(t_stc **stack)
{
	t_stc	*tail;

	tail = *stack;
	while (tail->next)
		tail = tail->next;
	return (tail);
}

char	*ft_free_pp(char **p_p)
{
	int	i;

	i = 0;
	if (!p_p)
		return (NULL);
	while (p_p[i])
	{
		free(p_p[i]);
		i++;
	}
	free (p_p);
	return (NULL);
}

void	free_stacks(t_stc **stack_a, t_stc **stack_b)
{
	t_stc	*tmp;

	if (stack_a)
	{
		while (*stack_a)
		{
			tmp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = tmp;
		}
	}
	if (stack_b)
	{
		while (*stack_b)
		{
			tmp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = tmp;
		}
	}
}
