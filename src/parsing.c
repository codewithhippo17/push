/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:46:00 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/22 06:29:03 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	space_exist(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			return (true);
		i++;
	}
	return (false);
}

bool	is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	if (i == 0 || (i == 1 && (str[0] == '-' || str[0] == '+')))
		return (false);
	return (true);
}

bool	ft__atoi(t_stack **a, const char *nptr)
{
	unsigned int	res;
	unsigned int	sign;
	int				i;

	i = 0;
	res = 0;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - 48;
		if (res > 2147483647 && sign == 1)
			return (false);
		else if (res > 2147483648 && sign == (unsigned int)-1)
			return (false);
		i++;
	}
	return (ft_add_back(a, (res * sign)));
}

bool	ft_atoi_2d(t_stack **a, char **input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (is_int(input[i]) == true)
		{
			if (ft__atoi(a, input[i]) == false)
				return (false);
		}
		else
			return (false);
		i++;
	}
	return (true);
}

bool	ft_parsing(t_stack **a, int ac, char **input)
{
	char	**tmp;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (space_exist(input[i]) == true)
		{
			tmp = ft_split(input[i], ' ');
			if (!tmp || !tmp[0])
				return (false);
			if (ft_atoi_2d(a, tmp) == false)
				return (ft_free_split(tmp), false);
			ft_free_split(tmp);
		}
		else if (is_int(input[i]) == true)
		{
			if (ft__atoi(a, input[i]) == false)
				return (false);
		}
		else
			return (false);
		i++;
	}
	return (true);
}
