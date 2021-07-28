/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:20:34 by ichougra          #+#    #+#             */
/*   Updated: 2021/07/28 12:58:24 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

struct	s_rules;

typedef struct s_philo
{
	int				id;
	int				x_ate;
	int				left_fork_id;
	int				right_fork_id;
	long long		last_meal;
	struct s_arg	*arg;
	pthread_t		thread_id;
}	t_philo;

typedef struct s_arg
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	int				dieded;
	int				all_ate;
	long long		timestamp;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	writing;
	t_philo			philo[250];
}				t_arg;

int				ft_atoi(const char *str);
int				error(int ac, char **av, t_arg *philo);
int				init_struct(t_arg *philo, char **av, int ac);
long long		times(void);
long long		time_diff(long long past, long long pres);
void			*funct(void *v_philo);
int				create_philo(t_arg *arg);
void			check_death(t_arg *r, t_philo *p);
void			action_print(t_arg *rules, int id, char *string);
void			smart_sleep(long long time, t_arg *rules);

#endif