/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 03:38:56 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/21 03:58:15 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_b(t_stack **a, t_stack **b, int min_idx, int a_size)
{
	if (min_idx <= a_size / 2)
	{
		while ((*a)->pos != 0)
			ra(a);
	}
	else
	{
		while ((*a)->pos != 0)
			rra(a);
	}
	pb(a, b);
}

void	ft_sort_five(t_stack **a, t_stack **b, int a_size)
{
	int	min_idx;
	int min_pos;
	
	min_pos = 0;
	while (a_size >= 2)
	{
		min_idx = find_min(a, min_pos);
		push_b(a, b, min_idx, a_size);
		min_pos--;
		a_size--;
	}
	if ((*a)->pos > (*a)->next->pos)
	{
		sa(a);
	}
	while ((*a)->pos != 0)
	{
		pa(a, b);
	}
}

void	ft_sort(t_stack **a, t_stack **b, int size)
{
	if (size <= 5)
	{
		ft_sort_five(a, b, size);
		return ;
	}
	push_to_b(a, b, size);
	push_to_a(a, b);
}

int	main(int ac, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	b = NULL;
	a = NULL;
	if (ft_parsing(&a, ac, argv) == false)
	{
		write(2, "Error", 5);
		return (ft_clean(&a), 0);
	}
	size = ft_stacksize(a);
	if (ft_posission(&a) == false)
	{
		write(2, "Error", 5);
		return (ft_clean(&a), 0);
	}
	if (is_sorted(&a, size) == false)
	{
		write(2, "Error", 5);
		return (ft_clean(&a), 0);
	}
	printf("%d", find_min(&a, 0));
	ft_sort(&a, &b, size);
	print_stack(&a);
	ft_clean(&a);
	return (0);
}
