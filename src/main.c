/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:16:12 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/03 21:20:09 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_stc **stc_a, t_stc **stc_b)
{
	t_stc	*printer;

	ft_putstr_fd("--A--\n", 1);
		printer = *stc_a;
	while (printer)
	{
		ft_putnbr_fd(printer->val, STDOUT_FILENO);
		ft_putchar_fd('\n', 1);
		printer = printer->next;
	}
	pb(stc_a, stc_b);
	pb(stc_a, stc_b);
	sb(stc_b);
	pb(stc_a, stc_b);
	sa(stc_a);
	pa(stc_a, stc_b);
	pa(stc_a, stc_b);
	pa(stc_a, stc_b);
}

int	main(int argc, char **argv)
{
	t_stc	*stc_a;
	t_stc	*stc_b;
	t_inf	s_inf;
	// t_stc	*printer;

	initiate_data(&stc_a, &stc_b, &s_inf);
	if (argc >= 2)
	{
		if (argc == 2)
		{
			if (one_str_input(&stc_a, &s_inf, argv[1]) != 0)
				return (1);
		}
		else
		{
			s_inf.elements = argc - 1;
			if (create_stack(&stc_a, &s_inf, argv + 1) != 0)
				return (1);
		}
		// printer = stc_a;
		// while (printer)
		// {
		// 	ft_putnbr_fd(printer->val, STDOUT_FILENO);
		// 	ft_putchar_fd('\n', 1);
		// 	printer = printer->next;
		// }
		sort_few(&stc_a, &stc_b, &s_inf);
		// ft_putstr_fd("--A--\n", 1);
		// printer = stc_a;
		// while (printer)
		// {
		// 	ft_putnbr_fd(printer->val, STDOUT_FILENO);
		// 	ft_putchar_fd('\n', 1);
		// 	printer = printer->next;
		// }
		free_stack(&stc_a);
		free_stack(&stc_b);
	}
	return (0);
}
