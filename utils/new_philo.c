/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:54:29 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/24 19:44:32 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*new_philo(int id, t_fork *r, t_fork *l, int max)
{
	t_philo	*node;

	node = (t_philo *)malloc(sizeof(t_philo));
	if (!node)
		return (node);
	node->id = id;
	node->lf = l;
	node->rf = r;
	node->last_eat = 0;
	node->n_eat = 0;
	node->max_eat = max;
	pthread_mutex_init(&node->lock, NULL);
	node->next = NULL;
	return (node);
}
