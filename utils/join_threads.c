/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:27:44 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/06/25 15:10:59 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	join_threads(t_num *n)
{
	t_philo	*tmp;

	tmp = n->p;
	while (1)
	{
		pthread_join(*tmp->thrd, NULL);
		if (tmp->id > tmp->next->id)
			return ;
		tmp = tmp->next;
	}
}
