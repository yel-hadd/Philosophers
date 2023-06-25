/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:21:40 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/06/25 17:20:05 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_num	*allocate_node(void)
{
	t_num	*node;

	node = (t_num *)malloc(sizeof(t_num));
	if (!node)
		return (NULL);
	node->f = NULL;
	node->p = NULL;
	node->next = NULL;
	return (node);
}

void	fill_params(t_num *node, char **arg, int arg_count)
{
	node->n_phil = ft_atoi(arg[1]);
	node->ttd = ft_atoi(arg[2]);
	node->tte = ft_atoi(arg[3]);
	node->tts = ft_atoi(arg[4]);
	node->max_eat = -2;
	if (arg_count == 6)
		node->max_eat = ft_atoi(arg[5]);
}

pthread_mutex_t	*allocate_mutex(void)
{
	pthread_mutex_t	*lock;

	lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (lock == NULL)
		return (NULL);
	return (lock);
}

void	initialize_mutexes(t_num *node)
{
	node->lock = allocate_mutex();
	node->plock = allocate_mutex();
	pthread_mutex_init(node->lock, NULL);
	pthread_mutex_init(node->plock, NULL);
}

t_num	*parse_params(char **arg, int arg_count)
{
	t_num	*node;

	node = allocate_node();
	if (!node)
		return (node);
	fill_params(node, arg, arg_count);
	initialize_mutexes(node);
	return (node);
}
