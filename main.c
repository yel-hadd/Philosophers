/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:24:45 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/07 21:38:41 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
*/

int	main(int ac, char **av)
{
	t_num	*n;
	t_fork	*fork;
	long	time;
	t_philo	*tmp;
	//pthread_mutex_t	lock;

	//pthread_mutex_init(&lock, NULL);
	time = get_ms_ts(0);
	n = NULL;
	fork = NULL;
	n = parse_params(av, ac, time);
	if (!check_params(n))
		return (1);
	parse_forks(&n->f, n->n_phil);
	parse_philos(n, &n->f, n->n_phil);
	tmp = n->p;
	while (tmp != NULL)
	{
		pthread_create(tmp->thrd, NULL, routine, tmp);
		tmp = tmp->next;
	}
	tmp = n->p;
	while (tmp != NULL)
	{
		pthread_join(*tmp->thrd, NULL);
		tmp = tmp->next;
	}
	return (0);
}

/*
	while (n->p != NULL)
	{
		printf("id: %d | right fork id : %d | left fork id : %d\n", n->p->id, n->p->rf->id, n->p->lf->id);
		n->p = n->p->next;
	}
*/