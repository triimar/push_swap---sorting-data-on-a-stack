/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:16:12 by tmarts            #+#    #+#             */
/*   Updated: 2023/05/12 21:52:22 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				return (EXIT_FAILURE);
		}
		else
		{
			s_inf.elements = argc - 1;
			if (create_stack(&stc_a, &s_inf, argv + 1) != 0)
				return (EXIT_FAILURE);
		}
		// printer = stc_a;
		// while (printer)
		// {
		// 	ft_putnbr_fd(printer->val, STDOUT_FILENO);
		// 	ft_putchar_fd('\n', 1);
		// 	printer = printer->next;
		// }
		if (order_check(&stc_a))
			return (EXIT_SUCCESS);
		if (s_inf.elements > 1 && s_inf.elements < 6)
			sort_few(&stc_a, &stc_b, &s_inf);
		else
		{
			pre_sorter(&stc_a, &stc_b, &s_inf);
			sorter(&stc_a, &stc_b, &s_inf);
		}

		// ft_putstr_fd("--A--\n", 1);
		// printer = stc_a;
		// while (printer)
		// {
		// 	ft_putnbr_fd(printer->val, STDOUT_FILENO);
		// 	ft_putchar_fd(' ', 1);
		// 	printer = printer->next;
		// }
		// ft_putchar_fd('\n', 1);
		// printer = stc_a;
		// while (printer)
		// {
		// 	ft_putnbr_fd(printer->index, STDOUT_FILENO);
		// 	ft_putchar_fd(' ', 1);
		// 	printer = printer->next;
		// }
		// int size = (int)log2(s_inf.elements) + 1;
		// ft_putnbr_fd(size, 1);
		// ft_putchar_fd(' ', 1);
		free_stack(&stc_a);
		free_stack(&stc_b);
	}
	return (EXIT_SUCCESS);
}
