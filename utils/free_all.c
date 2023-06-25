/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:28:18 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/06/25 19:05:26 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_forks(t_fork *f)
{
	t_fork	*current;
	t_fork	*temp;

	current = f;
	while (current)
	{
		temp = current->next;
		pthread_mutex_unlock(current->lock);
		pthread_mutex_destroy(current->lock);
		free(current->lock);
		free(current);
		current = temp;
	}
	f = NULL;
}

void	free_philos(t_philo *head)
{
	t_philo	*next_node;
	int		first_time;
	t_philo	*current;

	if (head == NULL)
		return ;
	current = head;
	first_time = 1;
	while (first_time || current != head)
	{
		first_time = 0;
		next_node = current->next;
		free(current->thrd);
		free(current);
		current = next_node;
	}
	head = NULL;
}

void	free_all(t_num *head)
{
	t_num	*tmp;

	free_forks(head->f);
	free_philos(head->p);
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		pthread_mutex_destroy(tmp->lock);
		pthread_mutex_destroy(tmp->plock);
		free(tmp->lock);
		free(tmp->plock);
		free(tmp);
	}
	head = NULL;
}
