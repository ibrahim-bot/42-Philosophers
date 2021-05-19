/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:44:42 by ibrahim           #+#    #+#             */
/*   Updated: 2021/05/19 11:38:14 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nbr;

	sign = 1;
	i = 0;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (int)str[i++] - '0';
	return (nbr * sign);
}

int error(int ac, char **av)
{
	int i;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		write(1, "ADD 5 or 6 arg\n", 16);
		return (-1);
	}
	if (ft_atoi(av[1]) < 1)
	{
		write(1, "Error: add more philosopher\n", 29);
		return (-1);
	}
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
		{
			write(1, "Error: argument must be > 0\n", 29);
			return (-1);
		}
		i++;
	}
	return (0);  
}
