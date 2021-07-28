/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:08:44 by ichougra          #+#    #+#             */
/*   Updated: 2021/07/28 12:49:59 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eats(t_philo*philo)
{
	t_arg	*rules;

	rules = philo->arg;
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	action_print(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	action_print(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->meal_check));
	action_print(rules, philo->id, "is eating");
	philo->last_meal = times();
	pthread_mutex_unlock(&(rules->meal_check));
	smart_sleep(rules->t_eat, rules);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
}

void	*funct(void *void_philosopher)
{
	int		i;
	t_philo	*philo;
	t_arg	*rules;

	i = 0;
	philo = (t_philo *)void_philosopher;
	rules = philo->arg;
	 if (philo->id % 2)
		usleep(15000);
	while (!(rules->dieded))
	{
		philo_eats(philo);
		if (rules->all_ate)
			break ;
		action_print(rules, philo->id, "is sleeping");
		smart_sleep(rules->t_sleep, rules);
		action_print(rules, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_arg	val;

	if (error(ac, av, &val) == -1)
		return (-1);
	if (create_philo(&val) == 1)
		return (84);
	return (0);
}
