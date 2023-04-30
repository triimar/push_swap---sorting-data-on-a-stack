/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:16:12 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/30 20:08:50 by tmarts           ###   ########.fr       */
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
	// ft_putstr_fd("--A--\n", 1);
	// printer = *stc_a;
	// while (printer)
	// {
	// 	ft_putnbr_fd(printer->value, STDOUT_FILENO);
	// 	ft_putchar_fd('\n', 1);
	// 	printer = printer->next;
	// }
	// ft_putstr_fd("--B--\n", 1);
	// printer = *stc_b;
	// while (printer)
	// {
	// 	ft_putnbr_fd(printer->value, STDOUT_FILENO);
	// 	ft_putchar_fd('\n', 1);
	// 	printer = printer->next;
	// }
}


int	main(int argc, char **argv)
{
	t_stc	*stc_a;
	t_stc	*stc_b;
	t_inf	s_inf;
	t_stc	*printer;

	stc_a = NULL;
	stc_b = NULL;
	if (argc >= 2)
	{
		if (argc == 2)
		{
			if (in_one_str(&stc_a, &s_inf, argv[1]) != 0)
				return (1);
		}
		else
		{
			s_inf.elements = argc - 1;
			if (create_stack(&stc_a, &s_inf, argv + 1) != 0)
				return (1);
		}
		if (dup_check(&stc_a) || order_check(&stc_a))
			input_error(&stc_a, NULL);
		sort_few(&stc_a, &stc_b, &s_inf);
		// move(&stc_a, &stc_b);
		// sa(&stc_a);
		ft_putstr_fd("--A--\n", 1);
		printer = stc_a;
		while (printer)
		{
			ft_putnbr_fd(printer->val, STDOUT_FILENO);
			ft_putchar_fd('\n', 1);
			printer = printer->next;
		}
		free_stack(&stc_a);
		free_stack(&stc_b);
	}
	// system("leaks push_swap");
	return (0);
}
