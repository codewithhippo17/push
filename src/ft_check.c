/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:56:43 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/20 00:12:06 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ft_posission(t_stack **a)
{
	t_stack	*current;
	t_stack	*small;

	small = NULL;
	current = *a;
	while (current)
	{
		small = *a;
		while (small)
		{
			if (small == current)
				small = small->next;
			if (small && current->value > small->value)
				current->pos += 1;
			else if (small && current->value == small->value)
				return (false);
			if (small)
			{
				small = small->next;
			}
		}
		current = current->next;
	}
	return (true);
}

bool	is_sorted(t_stack **a, int size)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = *a;
	while (current && i == current->pos)
	{
		current = current->next;
		if (current)
			i++;
	}
	if (i == size - 1)
		return (false);
	return (true);
}