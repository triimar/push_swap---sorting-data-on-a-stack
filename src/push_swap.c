/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:05:19 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/14 18:52:12 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	if (s_inf->elements == 2)
		sa(stc_a);
	else if (s_inf->elements == 3)
		sort_three(stc_a);
	else if (s_inf->elements == 4 || s_inf->elements == 5)
		sort_four_five(stc_a, stc_b, s_inf);
	else if (s_inf->elements > 5)
	{
		init_sorting(s_inf);
		sort_many(stc_a, stc_b, s_inf);
	}
	return ;
}
