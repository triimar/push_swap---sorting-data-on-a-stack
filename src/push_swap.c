/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:55:38 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/10 02:24:29 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

void	sorter(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	int	index;
	int size;
	int	i;
	int	j;

	i = 0;
	if (order_check(stc_a))
		return ;
	size = (int)log2(s_inf->elements);
	while (i <= size)
	{
		j = 0;
		while (j < s_inf->elements)
		{
			index = (*stc_a)->index;
			if ((index >> i) & 1)
				ra(stc_a);
			else
				pb(stc_a, stc_b);
			if (order_check(stc_a))
			{
				if (!(*stc_b))
					return ;
				j++;
				break ;
			}
			j++;		
		}
		i++;
		while (*stc_b)
		{
			// index = (*stc_b)->index;
			// if (((index >> i) & 1))
			// 	rrb(stc_b);
			pa(stc_a, stc_b);
		}
	}
}

// static void	sort_leftovers(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf, int size)
// {
// 	int	index;
// 	int	i;
// 	int	j;
// 	int bits;
// 	int pushes;
	
// 	i = 0;
// 	pushes = 0;
// 	if (order_check(stc_a))
// 		return ;
// 	bits = (int)log2(s_inf->elements);
// 	// ft_putnbr_fd(s_inf->elements, 1);
// 	// ft_putchar_fd(' ', 1);
// 	while (i <= bits)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			index = (*stc_a)->index;
// 			if (!(*stc_b) && order_check(stc_a))
// 				return ;
// 			if ((index >> i) & 1)
// 				ra(stc_a);
// 			else
// 			{
// 				pb(stc_a, stc_b);
// 				pushes++;
// 			}
// 			if (order_check(stc_a))
// 			{
// 				j++;
// 				break ;
// 			}
// 			j++;		
// 		}
// 		i++;
// 		while (pushes > 0)
// 		{
// 			pa(stc_a, stc_b);
// 			pushes--;
// 		}
			
// 	}
// }

// void	sorter(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
// {
// 	int	index;
// 	int	i;
// 	int	j;
// 	int rotations;
// 	int size;

// 	rotations = 0;
// 	i = 0;
// 	if (order_check(stc_a))
// 		return ;
// 	size = (int)log2(s_inf->elements) + 1;
// 	i = size - 1;
// 	// ft_putnbr_fd(s_inf->elements, 1);
// 	// ft_putchar_fd(' ', 1);
// 	while (i >= 0)
// 	{
// 		j = 0;
// 		int moves = s_inf->elements - rotations;
// 		while (j < moves)
// 		{
// 			index = (*stc_a)->index;
// 			if (!(*stc_b) && order_check(stc_a))
// 				return ;
// 			if ((index >> i) & 1)
// 			{
// 				pb(stc_a, stc_b);
// 				rotations++;
// 			}
// 			else
// 			{
// 				ra(stc_a);
				
// 			}
// 			j++;	
// 		}
// 		// while (*stc_b)
// 		// 	pa(stc_a, stc_b);
// 		i--;
// 		// j = 0;
// 		// moves = s_inf->elements - rotations;
// 		// while (j < moves)
// 		// {
// 		// 	index = (*stc_b)->index;
// 		// 	if ((index >> i) & 1)
// 		// 	{
// 		// 		rb(stc_b);
// 		// 	}
// 		// 	else
// 		// 		pa(stc_a, stc_b);	
// 		// 	j++;
// 		// }

// 	}

// }


