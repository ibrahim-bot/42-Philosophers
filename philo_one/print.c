/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrahim <ibrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 02:18:34 by ibrahim           #+#    #+#             */
/*   Updated: 2021/06/30 02:37:16 by ibrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    action_print(t_arg *rules, int id, char *string)
{
	pthread_mutex_lock(&(rules->writing));
	if (!(rules->dieded))
	{
		printf("%lli ", times() - rules->timestamp);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(rules->writing));
	return ;
}