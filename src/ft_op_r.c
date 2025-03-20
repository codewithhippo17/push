/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 02:40:29 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/20 02:41:46 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ra(t_stack **a)
{
	t_stack *first;
	t_stack *last;
	
	if (!(*a) || ft_stacksize(*a) < 3)
		return ;
	first = (*a)->next;
	last = ft_last(*a);
	last->next = *a;
	(*a)->next = NULL;
	(*a) = first;
	printf("ra\n");
}

void    rb(t_stack **b)
{
	t_stack *first;
	t_stack *last;
	
	if (!(*b) || ft_stacksize(*b) < 3)
		return ;
	first = (*b)->next;
	last = ft_last(*b);
	last->next = *b;
	(*b)->next = NULL;
	(*b) = first;
	printf("rb\n");
}

void    rra(t_stack **a)
{
	t_stack *first;
	t_stack *last;
	
	if (!(*a) || ft_stacksize(*a) < 3)
		return ;
	first = ft_last(*a);
	last = *a;
	while (last->next->next)
	{
		last = last->next;
	}
	first->next = *a;
	*a = first;
	last->next = NULL;
	printf("rra\n");
}

void    rrb(t_stack **b)
{
	t_stack *first;
	t_stack *last;
	
	if (!(*b) || ft_stacksize(*b) < 3)
		return ;
	first = ft_last(*b);
	last = *b;
	while (last->next->next)
	{
		last = last->next;
	}
	first->next = *b;
	*b = first;
	last->next = NULL;
	printf("rrb\n");
}