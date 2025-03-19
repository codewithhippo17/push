/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 03:38:56 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/19 04:00:57 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int g_size;

bool	ft_posission(t_stack **a)
{
	t_stack	*current;
	t_stack *small;

	small = NULL;
	current = *a;
	while (current)
	{
		small = *a;
		while (small)
		{
			if (small == current)
				small = small->next;
			if (current->value > small->value)
				current->pos += 1;
			if (current->value == small->value)
				return (false); 
			small = small->next;
		}
		current = current->next;
	}
	return (true);
}

bool	is_sorted(t_stack **a)
{
	int i;
	t_stack	*current;

	i = 0;
	current = *a;
	while (current && i == current->pos)
	{
		current = current->next;
		i++;
	}
	if (i == g_size - 1)
		return (true);
	return (false);
}

int	main(int ac, char *argv[])
{
	t_stack	*a;
	// t_stack	*b;

	if (ac < 3)
		return (0);
	if (ft_parsing(&a, ac, argv) == false)
		return (ft_clean(&a), 0);
	g_size = ft_stacksize(a);
	if (is_sorted(&a) == false || ft_posission(&a) == false)
		return (ft_clean(&a), 0);
	
	
	return (0);
}
