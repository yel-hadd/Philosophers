/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:17:24 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/07 15:17:39 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	parse_forks(t_fork **f, int n_phil)
{
	int		i;

	i = -1;
	while (++i < n_phil)
		fork_add_back(f, new_fork(i));
}
