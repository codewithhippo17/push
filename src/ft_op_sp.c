/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:52:15 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/22 07:33:21 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **a, int w)
{
	t_stack	*first;
	t_stack	*second;

	if (*a == NULL || ft_stacksize(*a) == 1)
	{
		return ;
	}
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	if (w == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int w)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*b) || ft_stacksize(*b) == 1)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	if (w == 1)
		write(1, "sb\n", 3);
}

void	pb(t_stack **a, t_stack **b, int w)
{
	t_stack	*new;

	new = *a;
	*a = (*a)->next;
	new->next = NULL;
	ft_lstaddfront(b, new);
	if (w == 1)
		write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b, int w)
{
	t_stack	*new;

	new = *b;
	*b = (*b)->next;
	new->next = NULL;
	ft_lstaddfront(a, new);
	if (w == 1)
		write(1, "pa\n", 3);
}
