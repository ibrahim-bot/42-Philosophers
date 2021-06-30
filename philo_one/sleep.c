/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrahim <ibrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 02:19:30 by ibrahim           #+#    #+#             */
/*   Updated: 2021/06/30 02:20:28 by ibrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    smart_sleep(long long time, t_arg *rules)
{
	long long i;

	i = times();
	while (!(rules->dieded))
	{
		if (time_diff(i, times()) >= time)
			break ;
		usleep(50);
	}
}
