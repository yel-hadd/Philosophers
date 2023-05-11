/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:28:42 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/11 19:29:49 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_data(t_num *n)
{
	t_philo	*tmp;
	t_philo	*next;

	tmp = n->p;
	free(n->lock);
	free(n->plock);
	free_forks(n->f);
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp->thrd);
		free(tmp);
		tmp = next;
	}
	free(n);
}
