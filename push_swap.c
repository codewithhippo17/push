/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 03:38:56 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/22 08:10:19 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_b(t_stack **a, t_stack **b, int min_idx, int a_size)
{
	static int	min_pos;

	if (min_idx <= a_size / 2)
	{
		while ((*a)->pos != min_pos)
			ra(a, 1);
	}
	else
	{
		while ((*a)->pos != min_pos)
			rra(a, 1);
	}
	min_pos++;
	pb(a, b, 1);
}

void	ft_sort_five(t_stack **a, t_stack **b, int a_size)
{
	int	min_idx;
	int	min_pos;

	min_pos = 0;
	while (a_size > 2)
	{
		min_idx = find_min(a, min_pos);
		push_b(a, b, min_idx, a_size);
		min_pos++;
		a_size--;
	}
	if ((*a)->pos > (*a)->next->pos)
	{
		sa(a, 1);
	}
	while ((*a)->pos != 0)
	{
		pa(a, b, 1);
	}
}

void	ft_sort_three(t_stack **a, int max_idx)
{
	if (max_idx == 0)
		ra(a, 1);
	if (max_idx == 1)
		rra(a, 1);
	if ((*a)->pos != 0)
		sa(a, 1);
}

void	ft_sort(t_stack **a, t_stack **b, int size)
{
	int	max_idx;

	if (size <= 3)
	{
		max_idx = find_max(a, size - 1);
		ft_sort_three(a, max_idx);
		return ;
	}
	if (size > 3 && size <= 5)
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
	if (ac < 2)
		return (0);
	if (ft_parsing(&a, ac, argv) == false)
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
	if (is_sorted(&a, size) == true)
		return (ft_clean(&a), 0);
	ft_sort(&a, &b, size);
	ft_clean(&a);
	return (0);
}
