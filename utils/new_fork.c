/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:54:34 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/28 14:15:03 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_fork	*new_fork(int id, int taken)
{
	t_fork	*node;

	pthread_mutex_t *lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (lock == NULL)
	    return NULL;
	node = (t_fork *)malloc(sizeof(t_fork));
	node->lock = lock;
	pthread_mutex_init(node->lock, NULL);
	if (!node)
		return (node);
	node->id = id;
    node->taken = taken;
	node->next = NULL;
	return (node);
}
