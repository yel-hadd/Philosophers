/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:27:13 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/06/25 16:07:07 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	start_threads(t_num *n)
{
	t_philo	*tmp;

	tmp = n->p;
	while (tmp != NULL)
	{
		pthread_create(tmp->thrd, NULL, routine, tmp);
		tmp = tmp->next;
	}
	tmp = n->p;
	while (tmp != NULL)
	{
		pthread_detach(*tmp->thrd);
		tmp = tmp->next;
	}
	check_death(make_circular(n->p), n);
}
