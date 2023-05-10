/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:31:44 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/10 23:13:13 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

#include "../philo.h"

/*
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
9160
*/

long long get_ms_ts(long subtract)
{
	struct timeval	tv;
	long long		time_stamp;

	gettimeofday(&tv, NULL);
	time_stamp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	time_stamp -= subtract;
	return (time_stamp);
}

void	ft_usleep(long tts, t_num *args, t_philo *m)
{
	long start;
	long long var;

	start  = get_ms_ts(0);
	while((get_ms_ts(0) - start < tts) && args->funeral != 1)
	{
		if (get_ms_ts(m->last_eat) >= args->ttd)
		{
			var = get_ms_ts(args->start_ts);
			pthread_mutex_lock(args->lock);
			args->funeral = 1;
			pthread_mutex_unlock(args->lock);
			printf("%lld\t%d\tdied\n", var, m->id);
			return;
		}
		usleep(10);
	}	
}

void	eating(t_num *args, t_philo *m)
{
	pthread_mutex_lock(args->lock);
	if (args->funeral == 1)
	{
		pthread_mutex_unlock(args->lock);
		return ;
	}
	m->last_eat = get_ms_ts(0);
	m->n_meals += 1;
	pthread_mutex_unlock(args->lock);
	pthread_mutex_lock(args->plock);
	printf("%lld\t%d\tis eating\n", get_ms_ts(args->start_ts), m->id);
	pthread_mutex_unlock(args->plock);
	ft_usleep(args->tte, args, m);
}

void	sleeping(t_num *args, t_philo *m)
{
	pthread_mutex_lock(args->lock);
	if (args->funeral == 1)
	{
		pthread_mutex_unlock(args->lock);
		return ;
	}
	pthread_mutex_lock(args->plock);
	printf("%lld\t%d\tis sleeping\n", get_ms_ts(args->start_ts), m->id);
	pthread_mutex_unlock(args->plock);
	ft_usleep(args->tts, args, m);
}

void	thinking(t_num *args, t_philo *m)
{
	pthread_mutex_lock(args->lock);
	if (args->funeral == 1)
	{
		pthread_mutex_unlock(args->lock);
		return ;
	}
	pthread_mutex_unlock(args->lock);
	pthread_mutex_lock(args->plock);
	printf("%lld\t%d\tis thinking\n", get_ms_ts(args->start_ts), m->id);
	pthread_mutex_unlock(args->plock);
}

void	take_lfork(t_num *args, t_philo *m)
{
	pthread_mutex_lock(args->lock);
	if (args->funeral == 1)
	{
		pthread_mutex_unlock(args->lock);
		return ;
	}
	pthread_mutex_lock(m->lf->lock);
	printf("%lld\t%d\thas taken a fork\n", get_ms_ts(args->start_ts), m->id);
	pthread_mutex_unlock(args->lock);
}

void	take_rfork(t_num *args, t_philo *m)
{
	pthread_mutex_lock(args->lock);
	if (args->funeral == 1)
	{
		pthread_mutex_unlock(args->lock);
		return ;
	}
	pthread_mutex_lock(m->rf->lock);
	printf("%lld\t%d\thas taken a fork\n", get_ms_ts(args->start_ts), m->id);
	pthread_mutex_unlock(args->lock);
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
		take_lfork(args, m);
		// PICK UP RIGHT FORK
		take_rfork(args, m);
		// EAT
		eating(args, m);
		// PUT DOWN LEFT FORK
		pthread_mutex_unlock(m->lf->lock);
		// PUT DOWN RIGHT FORK
		pthread_mutex_unlock(m->rf->lock);
		// SLEEP
		sleeping(args, m);
		// THINK
		thinking(args, m);
		printf("**\n");

	}
	return (NULL);
}