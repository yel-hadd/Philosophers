/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:31:44 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/11 17:55:01 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
	while(get_ms_ts(0) - start <= tts && args->funeral < 1)
	{
		if (get_ms_ts(m->last_eat) >= args->ttd && m->last_eat > 0)
		{
			pthread_mutex_lock(args->lock);
			args->funeral = 1;
			pthread_mutex_unlock(args->lock);
			printf("%ld\t%d\tdied\n", get_ms_ts(args->start_ts), m->id);
		}
		if (args->funeral == 1)
			return;
		usleep(10);
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
		if (args->funeral < 1)
			printf("%ld\t%d\thas taken a fork\n", get_ms_ts(args->start_ts), m->id);
		// PICK UP RIGHT FORK
		if (args->funeral < 1 && m->rf->id != m->lf->id)
		{
			pthread_mutex_lock(m->rf->lock);
			printf("%ld\t%d\thas taken a fork\n", get_ms_ts(args->start_ts), m->id);
		}
		// EAT
		pthread_mutex_lock(args->lock);
		m->n_meals += 1;
		m->last_eat = get_ms_ts(0);
		if (args->funeral < 1 && m->rf->id != m->lf->id)
		printf("%ld\t%d\tis eating\n", m->last_eat- args->start_ts, m->id);
		pthread_mutex_unlock(args->lock);
		ft_usleep(args->tte, args, m);
		// PUT DOWN LEFT FORK
		pthread_mutex_unlock(m->lf->lock);
		// PUT DOWN RIGHT FORK
		pthread_mutex_unlock(m->rf->lock);
		// SLEEP
		if (args->funeral < 1 && m->rf->id != m->lf->id)
		printf("%ld\t%d\tis sleeping\n", get_ms_ts(args->start_ts), m->id);
		ft_usleep(args->tts, args, m);
		// THINK
		if (args->funeral < 1 && m->rf->id != m->lf->id)
		printf("%ld\t%d\tis thinking\n", get_ms_ts(args->start_ts), m->id);
	}
	return (NULL);
}
