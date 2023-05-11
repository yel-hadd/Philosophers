/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:27:13 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/11 19:29:38 by yel-hadd         ###   ########.fr       */
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
}
