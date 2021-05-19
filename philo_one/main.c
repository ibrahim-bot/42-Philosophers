/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:08:44 by ichougra          #+#    #+#             */
/*   Updated: 2021/05/19 16:24:45 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_philo(t_philo *philo)
{
	printf("%d %d is eating\n", philo->arg.tf_eat, philo->id);
	usleep(philo->arg.tf_eat * 1000);
	
}

void	sleep_philo(t_philo *philo)
{
	printf("%d 1 is sleeping\n", philo->arg.t_sleep);
	usleep(philo->arg.t_sleep * 1000);
	
}

void	think_philo(t_philo *philo)
{
	printf("0 1 is thinking\n");
	
}

void *compt_time()
{
	printf("OUUUIIIIII\n");
	return (NULL);
}

void    *funct1(void *arg)
{
	t_philo *philo = (t_philo *)arg; 
	pthread_t time;
	int ret;

	ret = pthread_create(&time, NULL, compt_time, NULL);
	if (ret)
	{
		write(1, "Error: pthread\n", 16);
		return (NULL);
	}
	while (1)
	{
		eat_philo(philo);
		// sleep_philo(philo);
		// think_philo(philo);
	}
	return (NULL);
}

void reading(char **av, pthread_t *t1, t_philo *philo)
{
	int i;
	int ret;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philo->id = i;
		ret = pthread_create(&t1[i], NULL, funct1, (void *)philo);
		if (ret)
		{
			write(1, "Error: pthread\n", 16);
			return ;
		}
		i++;
	}
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_join(t1[i], NULL);
		i++;
	}
}

int main(int ac, char **av)
{
	pthread_t *t1;
	t_philo philo;

	if (error(ac, av) == -1)
		return (-1);
	init_struct(&philo, av, ac);
	t1 = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	reading(av, t1, &philo);
	free(t1);
	return (0);
}