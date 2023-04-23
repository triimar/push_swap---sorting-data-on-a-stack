/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:48:52 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/23 21:53:22 by tmarts           ###   ########.fr       */
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

static int	ft_pushswap_atoi(const char *str)
{
	int		intvalue;
	int		neg_pos;
	char	*chr;

	intvalue = 0;
	neg_pos = 1;
	chr = (char *)str;
	while ((*chr == ' ' || *chr == '\f' || *chr == '\n'
			|| *chr == '\r' || *chr == '\t' || *chr == '\v'))
		chr++;
	if (*chr == '-' || *chr == '+')
	{
		neg_pos = atoi_negative(chr);
		chr++;
	}
	if (!(*chr >= '0' && *chr <= '9'))
		input_error((char *)str);
	while (*chr >= '0' && *chr <= '9')
	{
		if (intvalue > (INT_MAX - (*chr - '0')) / 10)
			input_error((char *)str);
		intvalue = intvalue * 10 + (*chr - '0');
		chr++;
	}
	return ((int)(intvalue * neg_pos));
}

int	create_stack(t_stack **stack_a, t_inf *s_inf, char **argv)
{
	t_stack	*temp_tail;
	t_stack	*new;
	int		i;

	i = 0;
	while (++i <= s_inf->elements)
	{
		new = malloc(sizeof(t_stack));
		if (!new)
			return (1);
		new->value = ft_pushswap_atoi(argv[i]);
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
