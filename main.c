/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:24:45 by yel-hadd          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2023/05/11 16:38:29 by yel-hadd         ###   ########.fr       */
=======
/*   Updated: 2023/05/10 21:29:30 by yel-hadd         ###   ########.fr       */
>>>>>>> parent of c957e7f (Revert "fixed infinite loop")
=======
/*   Updated: 2023/05/10 21:29:30 by yel-hadd         ###   ########.fr       */
>>>>>>> parent of c957e7f (Revert "fixed infinite loop")
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
	while (tmp != NULL)
	{
		pthread_join(*tmp->thrd, NULL);
		tmp = tmp->next;
	}
<<<<<<< HEAD
=======
	
>>>>>>> parent of c957e7f (Revert "fixed infinite loop")
	return (0);
}
