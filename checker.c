/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:34:14 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/22 02:31:14 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int main(int ac, char*av[])
{
    t_stack	*a;
	// t_stack	*b;
	int		size;

	// b = NULL;
	a = NULL;
	if (ac < 2)
		return (0);
	if (ft_parsing(&a, ac, av) == false)
	{
		write(2, "Error\n", 6);
		return (ft_clean(&a), 0);
	}
	size = ft_stacksize(a);
	if (ft_posission(&a) == false)
	{
		write(2, "Error\n", 6);
		return (ft_clean(&a), 0);
	}
	if (is_sorted(&a, size) == false)
		return (ft_clean(&a), 0);
    ra(&a);
    sa(&a);
}
