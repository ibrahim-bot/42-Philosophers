/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:20:34 by ichougra          #+#    #+#             */
/*   Updated: 2021/05/19 16:13:14 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct	s_arg
{
	int pnb;
	int t_eat;
	int tf_eat;
	int t_sleep;
	int all_eat;
}				t_arg;

typedef struct	s_philo
{
	int		id;
	t_arg	arg;
} 				t_philo;

int				ft_atoi(const char *str);
int				error(int ac, char **av);
void			init_struct(t_philo *philo, char **av, int ac);

#endif