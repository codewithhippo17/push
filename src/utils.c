/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 02:46:32 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/19 03:58:02 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init(t_stack *new, int value)
{
	new->cost = 0;
	new->value = value;
	new->pos = 0;
	new->next = NULL;
}

t_stack	*ft_last(t_stack *a)
{
	t_stack	*current;

	if (!a)
		return (NULL);
	current = a;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	ft_add_back(t_stack **a, int value)
{
	t_stack	*current;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!a || !new)
		return ;
	ft_init(new, value);
	if (*a == NULL)
	{
		*a = new;
		return ;
	}
	current = ft_last(*a);
	current->next = new;
}

int	ft_stacksize(t_stack *stack_a)
{
	t_stack	*current;
	int		i;

	current = stack_a;
	i = 0;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}