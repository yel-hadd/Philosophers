/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:31:44 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/06/25 17:20:37 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	lock_print_unlock(char *s, t_philo *p)
{
	t_num	*args;

	args = p->args;
	pthread_mutex_lock(args->plock);
	printf("%ld\t%d\t%s\n", get_ms_ts(args->start_ts), p->id, s);
	pthread_mutex_unlock(args->plock);
}

void	*routine(void *ptr)
{
	t_philo	*m;

	m = (t_philo *)ptr;
	if (m->id % 2 != 0)
		usleep(m->args->tte);
	while (m->n_meals != m->args->max_eat)
	{
		pthread_mutex_lock(m->lf->lock);
		lock_print_unlock("has taken a fork", m);
		pthread_mutex_lock(m->rf->lock);
		lock_print_unlock("has taken a fork", m);
		pthread_mutex_lock(m->args->lock);
		m->last_eat = get_ms_ts(m->args->start_ts);
		pthread_mutex_unlock(m->args->lock);
		lock_print_unlock("is eating", m);
		ft_usleep(m->args->tte);
		m->n_meals += (m->args->max_eat != -2);
		pthread_mutex_unlock(m->lf->lock);
		pthread_mutex_unlock(m->rf->lock);
		lock_print_unlock("is sleeping", m);
		ft_usleep(m->args->tts);
	}
	return (NULL);
}
