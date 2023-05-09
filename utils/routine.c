/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:31:44 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/09 16:02:51 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
9160
*/

long get_ms_ts(long subtract)
{
	struct timeval	tv;
	long		time_stamp;

	gettimeofday(&tv, NULL);
	time_stamp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	time_stamp -= subtract;
	return (time_stamp);
}

void	ft_usleep(long tts, t_num *args, t_philo *m)
{
	long start;

	start  = get_ms_ts(0);
	while(get_ms_ts(0) - start <= tts)
	{
		if (get_ms_ts(m->last_eat) >= args->ttd && m->last_eat > 0)
		{
			pthread_mutex_lock(args->lock);
			args->funeral = 1;
			pthread_mutex_unlock(args->lock);
			pthread_mutex_lock(args->plock);
			printf("%ld\t%d\tdied\n", get_ms_ts(args->start_ts), m->id);
			break;
		}
		usleep(100);
	}
}

void    *routine(void *ptr)
{
	t_philo			*m;
	t_num			*args;

	m = (t_philo *) ptr;
	args = m->args;
	if (m->id % 2 == 0)
		usleep(1000);
	while (m->n_meals != args->max_eat && args->funeral < 1)
	{
		// PICK UP LEFT FORK
		pthread_mutex_lock(m->lf->lock);
		pthread_mutex_lock(args->plock);
		printf("%ld\t%d\thas taken a fork\n", get_ms_ts(args->start_ts), m->id);
		pthread_mutex_unlock(args->plock);
		// PICK UP RIGHT FORK
		pthread_mutex_lock(m->rf->lock);
		pthread_mutex_lock(args->plock);
		printf("%ld\t%d\thas taken a fork\n", get_ms_ts(args->start_ts), m->id);
		pthread_mutex_unlock(args->plock);
		// EAT
		pthread_mutex_lock(args->lock);
		m->last_eat = get_ms_ts(args->start_ts);
		m->n_meals += 1;
		pthread_mutex_unlock(args->lock);
		pthread_mutex_lock(args->plock);
		printf("%ld\t%d\tis eating\n", m->last_eat, m->id);
		pthread_mutex_unlock(args->plock);
		ft_usleep(args->tte, args, m);
		// PUT DOWN LEFT FORK
		pthread_mutex_unlock(m->lf->lock);
		// PUT DOWN RIGHT FORK
		pthread_mutex_unlock(m->rf->lock);
		// SLEEP
		pthread_mutex_lock(args->plock);
		printf("%ld\t%d\tis sleeping\n", get_ms_ts(args->start_ts), m->id);
		pthread_mutex_unlock(args->plock);
		ft_usleep(args->tts, args, m);
		// THINK
		pthread_mutex_lock(args->plock);
		printf("%ld\t%d\tis thinking\n", get_ms_ts(args->start_ts), m->id);
		pthread_mutex_unlock(args->plock);
	}
	return (NULL);
}
