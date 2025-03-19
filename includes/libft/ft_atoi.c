/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:09:08 by ehamza            #+#    #+#             */
/*   Updated: 2024/10/28 20:59:06 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	unsigned int	res;
	unsigned int	sign;

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
		{
			return (-1);
		}
		else if (res > 2147483648 && sign == (unsigned int)-1)
		{
			return (0);
		}
		i++;
	}
	return (sign * res);
}

// #include <stdlib.h>
// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_atoi("2566345678904567890118"));
// 	printf("%d\n", ft_atoi("256634567818"));
// 	printf("%d\n", ft_atoi("2147483648"));
// }
