/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:35:59 by ichougra          #+#    #+#             */
/*   Updated: 2021/05/19 16:13:19 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
