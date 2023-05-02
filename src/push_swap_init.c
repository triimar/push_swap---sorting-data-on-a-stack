/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:03:39 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/02 19:08:25 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initiate_data(t_stc **stc_a, t_stc **stc_b, t_inf *s_inf)
{
	*stc_a = NULL;
	*stc_b = NULL;
	s_inf->node_i = -1;
	// s_inf->in_order = 1;
}