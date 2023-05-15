/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:16:12 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/15 18:40:30 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stc	*stc_a;
	t_stc	*stc_b;
	t_inf	s_inf;

	init_data(&stc_a, &stc_b, &s_inf);
	if (argc >= 2)
	{
		if (argc == 2)
		{
			if (one_str_input(&stc_a, &s_inf, argv[1]) != 0)
				return (EXIT_FAILURE);
		}
		else
		{
			s_inf.elements = argc - 1;
			if (create_stack(&stc_a, &s_inf, argv + 1) != 0)
				return (EXIT_FAILURE);
		}
		if (order_check(&stc_a))
			return (EXIT_SUCCESS);
		else
			checker(&stc_a, &stc_b);
		free_stacks(&stc_a, &stc_b);
	}
	return (EXIT_SUCCESS);
}
