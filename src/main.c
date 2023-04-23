/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:16:12 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/23 22:33:07 by tmarts           ###   ########.fr       */
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
		printer = stack_a;
		while (printer)
		{
			ft_putnbr_fd(printer->value, STDOUT_FILENO);
			ft_putchar_fd('\n', 1);
			printer = printer->next;
		}
		sa(&stack_a);
		printer = stack_a;
		while (printer)
		{
			ft_putnbr_fd(printer->value, STDOUT_FILENO);
			ft_putchar_fd('\n', 1);
			printer = printer->next;
		}		
	}
	return (0);
}
