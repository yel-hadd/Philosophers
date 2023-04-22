/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:54:34 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/22 20:45:26 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_fork	*new_fork(int id, int taken)
{
	t_fork	*node;

	node = (t_fork *)malloc(sizeof(t_fork));
	if (!node)
		return (node);
	node->id = id;
    node->taken = taken;
	node->next = NULL;
	return (node);
}