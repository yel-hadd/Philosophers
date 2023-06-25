/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:31:44 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/06/25 13:02:37 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*pickup_forks(t_philo *m)
{
	pthread_mutex_lock(m->lf->lock);
	if (m->args->funeral < 1)
		printf("%ld\t%d\thas taken a fork\n", get_ms_ts(m->args->start_ts),
				m->id);
	if (m->args->funeral < 1 && m->rf->id != m->lf->id)
	{
		pthread_mutex_lock(m->rf->lock);
		printf("%ld\t%d\thas taken a fork\n", get_ms_ts(m->args->start_ts),
				m->id);
	}
	return (m);
}

t_philo	*start_eating(t_philo *m, t_num *args)
{
	pthread_mutex_lock(args->lock);
	m->n_meals += 1;
	m->last_eat = get_ms_ts(0);
	if (args->funeral < 1 && m->rf->id != m->lf->id)
		printf("%ld\t%d\tis eating\n", m->last_eat - args->start_ts, m->id);
	pthread_mutex_unlock(args->lock);
	ft_usleep(args->tte, args, m);
	return (m);
}

void	put_down_forks(t_philo *m)
{
	pthread_mutex_unlock(m->lf->lock);
	pthread_mutex_unlock(m->rf->lock);
}

t_philo	*start_sleeping(t_philo *m, t_num *args)
{
	if (args->funeral < 1 && m->rf->id != m->lf->id)
		printf("%ld\t%d\tis sleeping\n", get_ms_ts(args->start_ts), m->id);
	ft_usleep(args->tts, args, m);
	return (m);
}

t_philo	*start_thinking(t_philo *m, t_num *args)
{
	if (args->funeral < 1 && m->rf->id != m->lf->id)
		printf("%ld\t%d\tis thinking\n", get_ms_ts(args->start_ts), m->id);
	return (m);
}

void	*routine(void *ptr)
{
	t_philo *m;
	t_num *args;
	int one;

	m = (t_philo *)ptr;
	args = m->args;
	one = 0;
	if (m->id % 2 == 0)
		usleep(100);
	while (m->n_meals != args->max_eat && args->funeral < 1)
	{
		if (one != 1)
			m = pickup_forks(m);
		m = start_eating(m, args);
		put_down_forks(m);
		m = start_sleeping(m, args);
		m = start_thinking(m, args);
		if (one == 0 && args->n_phil == 1)
			one = 1;
	}
	return (NULL);
}