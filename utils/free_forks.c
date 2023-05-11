/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:28:18 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/11 19:29:45 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_forks(t_fork *f)
{
	t_fork	*next;

	while (f != NULL)
	{
		next = f->next;
		free(f->lock);
		free(f);
		f = next;
	}
}
