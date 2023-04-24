/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:31:44 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/24 19:52:09 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    *routine(void *ptr)
{
	struct timeval	t;
	t_num			*m;

	m = (t_num *) ptr;
	while (1)
	{
		pthread_mutex_lock(&m->current->lf->lock);
		pthread_mutex_lock(&m->current->rf->lock);
		pthread_mutex_lock(&m->current->lock);
		gettimeofday(&t, NULL);
		printf("%d %d has taken a fork", m->ms - t.tv_usec, m->current->id);
		gettimeofday(&t, NULL);
		printf("%d %d is eating", m->ms - t.tv_usec, m->current->id);
		m->current->last_eat = m->ms - t.tv_usec;
		usleep(100);
		pthread_mutex_unlock(&m->current->lf->lock);
		pthread_mutex_unlock(&m->current->rf->lock);
		pthread_mutex_unlock(&m->current->lock);
	}
}
