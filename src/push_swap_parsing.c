/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:48:52 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/02 19:20:25 by tmarts           ###   ########.fr       */
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

static int	ft_pushswap_atoi(const char *str, int *data)
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
			return (1);
		if (neg_pos == -1 && intvalue * -10 - (*chr - '0') == INT_MIN)
			return (INT_MIN);
		if (intvalue > (INT_MAX - (*chr - '0')) / 10)
			return (1);
		intvalue = intvalue * 10 + (*chr - '0');
		chr++;
	}
	*data = (int)(intvalue * neg_pos);
	return (0);
}

static void	ft_indexer(t_stc **stc_a, t_inf *inf, t_stc *tail, t_stc *new)
{
	t_stc	*modifier;

	if (!(*stc_a))
		new->index = 1;
	else if (tail && new->val > tail->val && tail->index == inf->node_i)
		new->index = tail->index + 1;
	else
	{
		// inf->in_order = 0;
		modifier = *stc_a;
		new->index = 1;
		while (modifier)
		{
			if (new->val == modifier->val)
				input_error(stc_a, new);
			if (new->val > modifier->val)
				new->index++;
			else if (new->val < modifier->val)
				modifier->index++;
			modifier = modifier->next;
		}
	}
	// if (inf->node_i == inf->elements - 1 && inf->in_order == 1)
	// 	input_error(stc_a, new);
}

int	create_stack(t_stc **stack_a, t_inf *s_inf, char **argv)
{
	t_stc	*temp_tail;
	t_stc	*new;

	temp_tail = NULL;
	while (++s_inf->node_i <= s_inf->elements - 1)
	{
		new = malloc(sizeof(t_stc));
		if (!new)
			return (1);
		if (ft_pushswap_atoi(argv[s_inf->node_i], &(new->val)))
			input_error(stack_a, new);
		new->next = NULL;
		ft_indexer(stack_a, s_inf, temp_tail, new);
		if (*stack_a == NULL)
		{
			*stack_a = new;
			temp_tail = *stack_a;
		}	
		else
		{
			temp_tail->next = new;
			temp_tail = temp_tail->next;
		}
	}
	return (0);
}

int	one_str_input(t_stc **stack_a, t_inf *s_inf, char *str)
{
	char	**split;
	int		i;
	int		j;

	i = -1;
	split = ft_split(str, ' ');
	if (!split)
		return (1);
	while (split[++i] != NULL)
	{
		j = -1;
		while (split[i][++j] != '\0')
		{
			if (!(ft_isdigit(split[i][j])) && split[i][j] != '-')
			{
				ft_free_pp(split);
				ft_putendl_fd("Error", 1);
				exit(EXIT_FAILURE);
			}
		}
	}
	s_inf->elements = i;
	if (create_stack(stack_a, s_inf, split) != 0)
		return (ft_free_pp(split), 1);
	return (ft_free_pp(split), 0);
}


