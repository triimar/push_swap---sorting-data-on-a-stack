/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:48:52 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/14 18:02:10 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	atoi_negative(char *c)
{
	if (*c == '-')
		return (-1);
	else
		return (1);
}

static int	ft_ps_atoi(const char *str, int *data)
{
	int		intvalue;
	int		neg_pos;
	char	*chr;

	intvalue = 0;
	neg_pos = 1;
	chr = (char *)str;
	while (chr && (*chr == ' ' || *chr == '\t'))
		chr++;
	if (chr && (*chr == '-' || *chr == '+') && *(chr + 1) != '\0')
		neg_pos = atoi_negative(chr++);
	while (*chr != '\0')
	{
		if (!(*chr >= '0' && *chr <= '9'))
			return (EXIT_FAILURE);
		if (neg_pos == -1 && intvalue * -10 - (*chr - '0') == INT_MIN)
			return (INT_MIN);
		if (intvalue > (INT_MAX - (*chr - '0')) / 10)
			return (EXIT_FAILURE);
		intvalue = intvalue * 10 + (*chr - '0');
		chr++;
	}
	*data = (int)(intvalue * neg_pos);
	return (EXIT_SUCCESS);
}

static t_stc	*new_tail(t_stc **stack_a, t_stc *tail, t_stc *new)
{
	if (*stack_a == NULL)
	{
		*stack_a = new;
		tail = *stack_a;
	}	
	else
	{
		tail->next = new;
		tail = tail->next;
	}
	return (tail);
}

int	create_stack(t_stc **stack_a, t_inf *s_inf, char **argv)
{
	t_stc	*temp_tail;
	t_stc	*new;
	int		val;

	temp_tail = NULL;
	while (++s_inf->node_i <= s_inf->elements - 1)
	{
		if (!(argv[s_inf->node_i][0]) || ft_ps_atoi(argv[s_inf->node_i], &val))
			input_error(stack_a, NULL);
		new = malloc(sizeof(t_stc));
		if (!new)
			return (free_stacks(stack_a, NULL), EXIT_FAILURE);
		new->next = NULL;
		new->val = val;
		ft_indexer(stack_a, s_inf, temp_tail, new);
		temp_tail = new_tail(stack_a, temp_tail, new);
	}
	return (EXIT_SUCCESS);
}

int	one_str_input(t_stc **stack_a, t_inf *s_inf, char *str)
{
	char	**split;
	int		i;

	if (!(*str))
		input_error(NULL, NULL);
	i = -1;
	split = ft_split(str, ' ');
	if (!split)
		return (EXIT_FAILURE);
	while (split[++i] != NULL)
	{
		if (!(is_valid_input(split[i])))
		{
			ft_free_pp(split);
			input_error(NULL, NULL);
		}
	}
	s_inf->elements = i;
	if (create_stack(stack_a, s_inf, split) != 0)
		return (ft_free_pp(split), EXIT_FAILURE);
	return (ft_free_pp(split), EXIT_SUCCESS);
}
