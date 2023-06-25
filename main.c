/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:24:45 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/06/25 15:54:00 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
*/

t_philo *make_circular(t_philo *ptr)
{
	t_philo	*copy;
	t_philo	*head;

	copy = ptr;
	head = ptr;
	while (copy->next != NULL)
		copy = copy->next;
	copy->next = head;
	return (head);
}

void	*check_death(t_philo *philos, t_num *args)
{
	while (1)
	{
		// pthread_mutex_lock(args->lock);
		if (get_ms_ts(philos->last_eat + args->start_ts) > args->ttd)
		{
			// printf("%ld  -  %d\n",get_ms_ts(philos->last_eat),args->ttd);
			usleep(500);
			printf("%ld\t%d\tdied\n", get_ms_ts(args->start_ts), philos->id);
			// pthread_mutex_unlock(args->lock);
			return (NULL);
		}
		if ((philos->n_meals >= args->max_eat) && args->max_eat != -2)
		{
			join_threads(args);
			// pthread_mutex_unlock(args->lock);
			return (NULL);
		}
		// pthread_mutex_unlock(args->lock);
		philos = philos->next;
	}
}


int	main(int ac, char **av)
{
	t_num *n;

	n = NULL;
	n = parse_params(av, ac, 0);
	if (!check_params(n))
		return (1);
	parse_forks(&n->f, n->n_phil);
	parse_philos(n, &n->f, n->n_phil);
	n->start_ts = get_ms_ts(0);
	start_threads(n);
	if (!check_death(make_circular(n->p), n))
		return 0;
	// join_threads(n);
	free_data(n);
	return (0);
}