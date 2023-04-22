/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:24:45 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/22 23:04:57 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_num	*n;
	t_fork	*fork;

	n = NULL;
	fork = NULL;
	n = parse_params(av, ac);
	if (!check_params(n))
		return (1);
	parse_forks(&n->f, n->n_phil);
	// parse_philos(t_num *n, t_fork **f, int n_phil)
	parse_philos(n, &n->f, n->n_phil);
	while (n->p != NULL)
	{
		printf("left: %d | right: %d\n", n->p->lf->id, n->p->rf->id);
		n->p = n->p->next;
	}
	return (0);
}
