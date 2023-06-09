/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:17:59 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/07 15:31:35 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_fork	*get_fork(t_fork *f, int id)
{
	int	i;

	i = 0;
	while (f != NULL && f->id != id)
		f = f->next;
	return (f);
}

void	parse_philos(t_num *n, t_fork **f, int n_phil)
{
	int		i;
	t_fork	*right;
	t_fork	*left;
	t_philo	*node;

	i = -1;
	while (++i < n_phil)
	{
		right = get_fork(*f, i);
		left = get_fork(*f, i - 1);
		if (i == 0)
			left = get_fork(*f, n_phil - 1);
		node = new_philo(i + 1, right, left);
		node->args = n;
		philo_add_back(&n->p, node);
	}
}
