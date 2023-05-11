/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:24:59 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/11 19:25:24 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_usleep(long tts, t_num *args, t_philo *m)
{
	long	start;

	start = get_ms_ts(0);
	while (get_ms_ts(0) - start <= tts && args->funeral < 1)
	{
		if (get_ms_ts(m->last_eat) >= args->ttd && m->last_eat > 0)
		{
			pthread_mutex_lock(args->lock);
			args->funeral = 1;
			pthread_mutex_unlock(args->lock);
			printf("%ld\t%d\tdied\n", get_ms_ts(args->start_ts), m->id);
		}
		if (args->funeral == 1)
			return ;
		usleep(10);
	}
}
