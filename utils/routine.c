/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:31:44 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/24 21:23:14 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
*/

void    *routine(void *ptr)
{
	struct timeval	t;
	t_philo			*m;

	m = (t_philo *) ptr;
	// THINK
	// PICK UP FORK
	// EAT
	// PUT DOWN FORK
	// SLEEP
	// CHECK IF PHILO DIED
}
