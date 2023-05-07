/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:16:04 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/07 21:10:27 by tmarts           ###   ########.fr       */
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

t_stc	*get_tail(t_stc **stack)
{
	t_stc	*tail;

	tail = *stack;
	while (tail->next)
		tail = tail->next;
	return (tail);
}

void	free_stack(t_stc **stack)
{
	t_stc	*tmp;

	if (stack)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			free(*stack);
			*stack = tmp;
		}
	}
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
