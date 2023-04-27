/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:31:44 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/27 21:37:00 by yel-hadd         ###   ########.fr       */
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

//void	print_message(pthread_mutex_t *lock, char *message, int id, long time)
//{
//	printf("%ld %d has taken a fork", get_ms_ts(m->start_ts), m->id);
//}

void    *routine(void *ptr)
{
	struct timeval	t;
	t_philo			*m;
	t_num			*args;
	pthread_mutex_t	*lock;

	m = (t_philo *) ptr;
	args = m->args;
	pthread_mutex_init(lock, NULL);
	// CHECK IF PHILO DIED
	while (m->n_meals < args->max_eat || args->max_eat == -2)
	{
		if (get_ms_ts(m->last_eat) > args->ttd)
			return (NULL);
		// PICK UP LEFT FORK
		pthread_mutex_lock(&m->lf->lock);
		printf("%ld %d has taken a fork", get_ms_ts(args->start_ts), m->id);
		// PICK UP RIGHT FORK
		pthread_mutex_lock(&m->rf->lock);
		printf("%ld %d has taken a fork", get_ms_ts(args->start_ts), m->id);
		// EAT
		m->last_eat = get_ms_ts(args->start_ts);
		printf("%ld %d is eating", m->last_eat, m->id);
		usleep(args->tte);
		m->n_meals += 1;
		// PUT DOWN LEFT FORK
		pthread_mutex_unlock(&m->lf->lock);
		printf("%ld %d put down a fork", get_ms_ts(args->start_ts), m->id);
		// PUT DOWN RIGHT FORK
		pthread_mutex_unlock(&m->rf->lock);
		printf("%ld %d put down a fork", get_ms_ts(args->start_ts), m->id);
		// SLEEP
		usleep(args->tts);
		printf("%ld %d put down a fork", get_ms_ts(args->start_ts), m->id);
		// THINK
		printf("%ld %d is thinking", get_ms_ts(args->start_ts), m->id);
	}
	return (NULL);
}
