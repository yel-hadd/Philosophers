/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:31:44 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/26 14:28:09 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
timestamp_in_ms X has taken a fork

timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
9160
*/

long get_ms_ts(long long subtract)
{
	struct timeval	tv;
	long		time_stamp;

	gettimeofday(&tv, NULL);
	time_stamp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	if (subtract > 0)
		time_stamp -= subtract;
	return (time_stamp);
}


void    *routine(void *ptr)
{
	struct timeval	t;
	t_philo			*m;

	m = (t_philo *) ptr;

	// PICK UP LEFT FORK
	pthread_mutex_lock(&m->lf->lock);
	// PICK UP RIGHT FORK
	pthread_mutex_lock(&m->rf->lock);
	// EAT
	printf("%ld %d is eating", get_ms_ts(m->id));
	m->n_meals += 1;
	usleep(m->tte);
	// PUT DOWN LEFT FORK
	pthread_mutex_unlock(&m->lf->lock);
	// PUT DOWN RIGHT FORK
	pthread_mutex_unlock(&m->rf->lock);
	// SLEEP
	usleep(m->tts);
	// CHECK IF PHILO DIED
	// THINK
}
