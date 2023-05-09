/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:21:40 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/09 14:57:42 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_num	*parse_params(char **arg, int arg_count, long time)
{
	t_num	*node;
	pthread_mutex_t *lock;

	node = (t_num *)malloc(sizeof(t_num));
	if (!node)
		return (node);
	node->n_phil = ft_atoi(arg[1]);
	node->ttd = ft_atoi(arg[2]);
	node->tte = ft_atoi(arg[3]);
	node->tts = ft_atoi(arg[4]);
	node->max_eat = -2;
	if (arg_count == 6)
		node->max_eat = ft_atoi(arg[5]);
	node->start_ts = time;
	lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (lock == NULL)
	    return NULL;
	node->lock = lock;
	lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (lock == NULL)
	    return NULL;
	node->plock = lock;
	pthread_mutex_init(node->lock, NULL);
	pthread_mutex_init(node->plock, NULL);
	node->f = NULL;
	node->p = NULL;
	node->next = NULL;
	node->funeral = 0;
	return (node);
}
