/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:24:45 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/09 15:59:10 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_num	*n;
	t_fork	*fork;
	long	time;
	t_philo	*tmp;

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
	// while (tmp != NULL)
	// {
	// 	pthread_join(*tmp->thrd, NULL);
	// 	tmp = tmp->next;
	// }
	// while (n->funeral < 1)
	// {
	// 	usleep(10);
	// }
	while (1);
	
	
	return (0);
}
