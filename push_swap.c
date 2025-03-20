/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 03:38:56 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/20 02:44:14 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_sort(t_stack **a, t_stack **b)
{
	
}



int	main(int ac, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	b = NULL;
	a = NULL;
	if (ac < 3)
		return (0);
	if (ft_parsing(&a, ac, argv) == false)
		return (ft_clean(&a), 0);
	size = ft_stacksize(a);
	if (ft_posission(&a) == false)
	{
		printf("duplicated numbers");
		return (ft_clean(&a), 0);
	}
	if (is_sorted(&a, size) == false)
	{
		printf("input is already sorted");
		return (ft_clean(&a), 0);
	}

	rra(&a);
	rra(&a);
	
	printf("#####  stack a  #####\n\n");
	t_stack *current = a;
	while (current)
	{
		printf("current->value : %d\na->pos : %d\n\n", current->value, current->pos);
		current = current->next;
	}
	
	printf("#####  stack b  #####\n\n");
	current = b;
	while (current)
	{
		printf("current->value : %d\na->pos : %d\n\n", current->value, current->pos);
		current = current->next;
	}
	return (0);
}
