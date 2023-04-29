/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:16:12 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/29 21:20:33 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*printer;

	ft_putstr_fd("--A--\n", 1);
		printer = *stack_a;
	while (printer)
	{
		ft_putnbr_fd(printer->value, STDOUT_FILENO);
		ft_putchar_fd('\n', 1);
		printer = printer->next;
	}
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sb(stack_b);
	pb(stack_a, stack_b);
	sa(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	// ft_putstr_fd("--A--\n", 1);
	// printer = *stack_a;
	// while (printer)
	// {
	// 	ft_putnbr_fd(printer->value, STDOUT_FILENO);
	// 	ft_putchar_fd('\n', 1);
	// 	printer = printer->next;
	// }
	// ft_putstr_fd("--B--\n", 1);
	// printer = *stack_b;
	// while (printer)
	// {
	// 	ft_putnbr_fd(printer->value, STDOUT_FILENO);
	// 	ft_putchar_fd('\n', 1);
	// 	printer = printer->next;
	// }
}

// int initial_check(char **argv)
// {
// 	int i;
	
// 	while (argv[i] != NULL)
// 	{
// 		ft_isdigit(argv[i][j] || argv[i][j] == ' ' ||)
// 	}
// }

int	dup_check(t_stack **stack)
{
	t_stack	*current;
	t_stack	*flip;
	int		i;
	int		j;

	current = (*stack)->next;
	i = 1;
	while (current)
	{
		flip = *stack;
		j = 0;
		while (j < i)
		{
			if (flip->value == current->value)
				return (1);
			flip = flip->next;
			j++;
		}	
		current = current->next;
		i++;
	}
	return (0);
}

int	order_check(t_stack **stack)
{
	t_stack	*current;
	t_stack	*flip;

	current = (*stack)->next;
	flip = *stack;
	while (current)
	{
		if (current->value < flip->value)
			return (0);
		else
		{
			current = current->next;
			flip = flip->next;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_inf	s_inf;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (argc == 2)
		{
			if (in_one_str(&stack_a, &s_inf, argv[1]) != 0)
				return (1);
		}
		else
		{
			s_inf.elements = argc - 1;
			if (create_stack(&stack_a, &s_inf, argv + 1) != 0)
				return (1);
		}
		if (dup_check(&stack_a) || order_check(&stack_a))
			input_error(&stack_a);
		move(&stack_a, &stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	system("leaks push_swap");
	return (0);
}
