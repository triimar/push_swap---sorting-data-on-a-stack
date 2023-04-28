/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:16:12 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/28 18:06:37 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_inf	s_inf;
	t_stack	*printer;

	if (argc > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		s_inf.elements = argc - 1;
		if (create_stack(&stack_a, &s_inf, argv) != 0)
			return (1);
		ft_putstr_fd("--A--\n", 1);
		printer = stack_a;
		while (printer)
		{
			ft_putnbr_fd(printer->value, STDOUT_FILENO);
			ft_putchar_fd('\n', 1);
			printer = printer->next;
		}
		// ft_putstr_fd("----\n", 1);
		// pb(&stack_a, &stack_b);
		// // pb(&stack_a, &stack_b);
		// ft_putstr_fd("--A--\n", 1);
		// printer = stack_a;
		// while (printer)
		// {
		// 	ft_putnbr_fd(printer->value, STDOUT_FILENO);
		// 	ft_putchar_fd('\n', 1);
		// 	printer = printer->next;
		// }
		// ft_putchar_fd('\n', 1);
		// pb(&stack_a, &stack_b);
		// pb(&stack_a, &stack_b);
		// printer = stack_a;
		// while (printer)
		// {
		// 	ft_putnbr_fd(printer->value, STDOUT_FILENO);
		// 	ft_putchar_fd('\n', 1);
		// 	printer = printer->next;
		// }
		// ft_putchar_fd('\n', 1);
		// ft_putstr_fd("--B--\n", 1);
		// printer = stack_b;
		// while (printer)
		// {
		// 	ft_putnbr_fd(printer->value, STDOUT_FILENO);
		// 	ft_putchar_fd('\n', 1);
		// 	printer = printer->next;
		// }
		// ft_putstr_fd("----\n", 1);
		// rrr(&stack_a, &stack_b);
		
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		sb(&stack_b);
		pb(&stack_a, &stack_b);
		sa(&stack_a);
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		ft_putstr_fd("--A--\n", 1);
		printer = stack_a;
		while (printer)
		{
			ft_putnbr_fd(printer->value, STDOUT_FILENO);
			ft_putchar_fd('\n', 1);
			printer = printer->next;
		}
		ft_putstr_fd("--B--\n", 1);
		printer = stack_b;
		while (printer)
		{
			ft_putnbr_fd(printer->value, STDOUT_FILENO);
			ft_putchar_fd('\n', 1);
			printer = printer->next;
		}
		while (stack_a)
		{
			printer = stack_a->next;
			free(stack_a);
			stack_a = printer;
		}	
	}
	return (0);
}
