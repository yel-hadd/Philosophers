/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:21:40 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/27 21:27:56 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_num	*parse_params(char **arg, int arg_count, long time)
{
	t_num	*node;

	node = (t_num *)malloc(sizeof(t_num));
	if (!node)
		return (node);
	node->n_phil = ft_atoi(arg[1]);
	node->ttd = ft_atoi(arg[2]);
	node->tte = ft_atoi(arg[3]);
	node->tts = ft_atoi(arg[4]);
	node->max_eat = -2;
	if (arg_count == 6)
		node->max_eat = ft_atoi(arg[5]);
	node->start_ts = time;
	node->f = NULL;
	node->p = NULL;
	node->next = NULL;
	return (node);
}
