/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 02:19:30 by ibrahim           #+#    #+#             */
/*   Updated: 2021/07/28 12:51:53 by ichougra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	smart_sleep(long long time, t_arg *rules)
{
	long long	i;

	i = times();
	while (!(rules->dieded))
	{
		if (time_diff(i, times()) >= time)
			break ;
		usleep(50);
	}
}
