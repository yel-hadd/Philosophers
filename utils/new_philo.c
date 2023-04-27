/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:54:29 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/27 21:26:04 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*new_philo(int id, t_fork *r, t_fork *l)
{
	t_philo	*node;

	node = (t_philo *)malloc(sizeof(t_philo));
	if (!node)
		return (node);
	node->id = id;
	node->lf = l;
	node->rf = r;
	node->last_eat = 0;
	node->n_meals = 0;
	node->next = NULL;
	return (node);
}
