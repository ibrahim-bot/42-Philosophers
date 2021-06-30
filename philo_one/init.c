/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrahim <ibrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:35:59 by ichougra          #+#    #+#             */
/*   Updated: 2021/06/30 01:36:20 by ibrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_arg *philo)
{
	int i;

	i = philo->nb_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(philo->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(philo->writing), NULL))
		return (1);
	// if (pthread_mutex_init(&(philo->meal_check), NULL))
	// 	return (1);
	return (0);
}

void	init_philo(t_arg *arg)
{
	int i;

	i = arg->nb_philo;
	while (--i >= 0)
	{
		arg->philo[i].id = i;
		arg->philo[i].x_ate = 0;
		arg->philo[i].left_fork_id = i;
		arg->philo[i].right_fork_id = (i + 1) % arg->nb_philo;
		arg->philo[i].last_meal = 0;
		arg->philo[i].arg = arg;
	}
	
}

int	init_struct(t_arg *philo, char **av, int ac)
{
	philo->nb_eat = -1;
	philo->nb_philo = ft_atoi(av[1]);
	philo->t_die = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->nb_eat = ft_atoi(av[5]);

	if (init_mutex(philo) == 1)
		return (1);
	init_philo(philo);
	return (0);
}
