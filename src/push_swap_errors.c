/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarts <tmarts@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:48:29 by tmarts            #+#    #+#             */
/*   Updated: 2023/04/23 21:51:46 by tmarts           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_error(char *str)
{	
	ft_putstr_fd("push_swap: ", STDERR_FILENO);
	ft_putstr_fd((char *)str, STDERR_FILENO);
	ft_putendl_fd(": invalid input", STDERR_FILENO);
	//free
	exit (EXIT_FAILURE);
}
