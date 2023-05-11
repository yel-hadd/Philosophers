/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:27:44 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/11 19:29:33 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	join_threads(t_num *n)
{
	t_philo	*tmp;

	tmp = n->p;
	while (tmp != NULL)
	{
		pthread_join(*tmp->thrd, NULL);
		tmp = tmp->next;
	}
}
