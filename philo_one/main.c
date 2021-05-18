/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:08:44 by ichougra          #+#    #+#             */
/*   Updated: 2021/05/18 18:32:04 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_philo(t_philo *philo)
{
	printf("%d 1 is eating\n", philo->arg.tf_eat);
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

void    *funct1(void *arg)
{
	t_philo *philo = arg;

	while (1)
	{
		eat_philo(philo);
		sleep_philo(philo);
		think_philo(philo);
	}
	return (NULL);
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

void init_struct(t_philo *philo, char **av, int ac)
{
	philo->arg.pnb = ft_atoi(av[1]);
	philo->arg.t_eat = ft_atoi(av[2]);
	philo->arg.tf_eat = ft_atoi(av[3]);
	philo->arg.t_sleep = ft_atoi(av[4]);
	philo->arg.all_eat = 0;
	if (ac == 6)
		philo->arg.all_eat = ft_atoi(av[5]);
}

void reading(char **av, pthread_t *t1, t_philo *philo)
{
	int i;
	int ret;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		ret = pthread_create(&t1[i], NULL, funct1, philo);
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