/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 23:47:05 by ibrahim           #+#    #+#             */
/*   Updated: 2021/07/28 12:48:16 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(int ac, char **av, t_arg *philo)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		write(1, "Wrong arg: ADD 5 or 6 arg\n", 27);
		return (-1);
	}
	if (ft_atoi(av[1]) < 2 || ft_atoi(av[1]) > 200)
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
	if (init_struct(philo, av, ac))
		return (-1);
	return (0);
}
