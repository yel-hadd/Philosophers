/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:22:02 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/06/25 18:07:23 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*check_death(t_philo *philos, t_num *args)
{
	while (1)
	{
		pthread_mutex_lock(args->lock);
		if (get_ms_ts(philos->last_eat + args->start_ts) > args->ttd)
		{
			if (args->max_eat == philos->n_meals)
				return (pthread_mutex_unlock(args->lock), NULL);
			usleep(500);
			pthread_mutex_lock(args->plock);
			printf("%ld\t%d\tdied\n", get_ms_ts(args->start_ts), philos->id);
			return (pthread_mutex_unlock(args->lock), NULL);
		}
		philos = philos->next;
		pthread_mutex_unlock(args->lock);
	}
}
