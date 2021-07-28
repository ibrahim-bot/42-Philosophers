/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 01:27:26 by ibrahim           #+#    #+#             */
/*   Updated: 2021/07/28 12:51:05 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	quit(t_arg *rules, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
		pthread_join(philos[i].thread_id, NULL);
	i = -1;
	while (++i < rules->nb_philo)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->writing));
}

int	create_philo(t_arg *arg)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = arg->philo;
	arg->timestamp = times();
	while (i < arg->nb_philo)
	{
		if (pthread_create(&(philo[i].thread_id), NULL, funct, &(philo[i])))
		{
			write(1, "Error: pthread_create failed\n", 30);
			return (1);
		}
		philo[i].last_meal = times();
		i++;
	}
	check_death(arg, arg->philo);
	quit(arg, philo);
	return (0);
}
