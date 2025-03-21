/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 02:47:24 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/21 03:55:15 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack **b, int min_pos)
{
	t_stack	*current;
	int		min_idx;

	min_idx = 0;
	current = *b;
	while (current->pos != min_pos)
	{
		current = current->next;
		min_idx++;
	}
	return (min_idx);
}

int	find_max(t_stack **b, int max_pos)
{
	t_stack	*current;
	int		max_idx;

	max_idx = 0;
	current = *b;
	while (current->pos != max_pos)
	{
		current = current->next;
		max_idx++;
	}
	return (max_idx);
}

void	do_inst(t_stack **a, t_stack **b, int max_idx, int b_size)
{
	if (max_idx <= b_size / 2)
	{
		while ((*b)->pos != b_size - 1)
			rb(b);
	}
	else
	{
		while ((*b)->pos != b_size - 1)
			rrb(b);
	}
	pa(a, b);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	int	max_idx;
	int	b_size;

	b_size = ft_stacksize(*b);
	while (b_size)
	{
		max_idx = find_max(b, b_size - 1);
		do_inst(a, b, max_idx, b_size);
		b_size--;
	}
}

void	push_to_b(t_stack **a, t_stack **b, int size)
{
	int	ch;
	int	i;

	i = 0;
	if (size > 5 && size <= 100)
		ch = 13;
	else if (size > 100)
		ch = 37;
	while (*a)
	{
		if ((*a)->pos < i)
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->pos < i + ch)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else
			ra(a);
	}
}

void print_stack(t_stack **b)
{
	printf("#####  stack a  #####\n\n");
	t_stack *current = *b;
	while (current)
	{
		printf("current->value : %d, pos %d\n\n", current->value, current->pos);
		current = current->next;
	}
}