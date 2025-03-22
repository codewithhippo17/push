/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:34:14 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/22 09:32:36 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	exec_op(t_stack **a, t_stack **b, char *op)
{
	if (ft_strncmp("pa\n", op, 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp("pb\n", op, 3) == 0)
		pb(a, b, 0);
	else if (ft_strncmp("sa\n", op, 3) == 0)
		sa(a, 0);
	else if (ft_strncmp("sb\n", op, 3) == 0)
		sb(b, 0);
	else if (ft_strncmp("ra\n", op, 3) == 0)
		ra(a, 0);
	else if (ft_strncmp("rb\n", op, 3) == 0)
		rb(b, 0);
	else if (ft_strncmp("rra\n", op, 4) == 0)
		rra(a, 0);
	else if (ft_strncmp("rrb\n", op, 4) == 0)
		rra(b, 0);
	else
		return (-1);
	return (0);
}

void	ft_checker(t_stack **a, t_stack **b)
{
	char	*op;
	int		fd;

	op = get_next_line(0);
	if (!op)
		return ;
	while (op)
	{
		fd = exec_op(a, b, op);
		free(op);
		op = get_next_line(fd);
		if (fd == -1)
		{
			ft_clean(a);
			ft_clean(b);
			write(2, "Error\n", 6);
			exit(1);
		}
		if (!op)
			return ;
	}
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	b = NULL;
	a = NULL;
	if (ac < 2)
		return (0);
	if (ft_parsing(&a, ac, av) == false)
		return (write(2, "Error\n", 6), ft_clean(&a), 0);
	size = ft_stacksize(a);
	if (ft_posission(&a) == false)
		return (write(2, "Error\n", 6), ft_clean(&a), 0);
	ft_checker(&a, &b);
	if (is_sorted(&a, size) == true && !b)
	{
		return (write(1, "OK\n", 3), ft_clean(&a), 0);
	}
	write(1, "KO\n", 3);
	return (ft_clean(&b), ft_clean(&a), 0);
}
