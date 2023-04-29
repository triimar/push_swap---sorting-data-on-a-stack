/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:48:52 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/29 21:55:47 by tmarts           ###   ########.fr       */
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
	if (chr && (*chr == '-' || *chr == '+'))
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

// void	add_node(t_stack **stack_a, t_stack *new_node)
// {
// 	t_stack	*temp_tail;
// 	t_stack	*new;

// 	if (*stack_a == NULL)
// 	{
// 		*stack_a = new;
// 		temp_tail = *stack_a;
// 	}	
// 	else
// 	{
// 		temp_tail->next = new;
// 		temp_tail = temp_tail->next;
// 	}
// }

int	create_stack(t_stack **stack_a, t_inf *s_inf, char **argv)
{
	t_stack	*temp_tail;
	t_stack	*new;
	int		i;

	i = -1;
	while (++i <= s_inf->elements - 1)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return (1);
		if (ft_pushswap_atoi(argv[i], &(new->value)))
		{
			free(new);
			input_error(stack_a);
		}
		new->next = NULL;
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

static char	*ft_free_split(char **p_p)
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

int	in_one_str(t_stack **stack_a, t_inf *s_inf, char *str)
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
				ft_free_split(split);
				ft_putendl_fd("Error", 1);
				exit(EXIT_FAILURE);
			}
		}
	}
	s_inf->elements = i;
	if (create_stack(stack_a, s_inf, split) != 0)
		return (ft_free_split(split), 1);
	return (ft_free_split(split), 0);
}
