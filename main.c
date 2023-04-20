/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:23:01 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/19 23:35:39 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *my_turn()
{
	int	i;

	i = -1;
	while(++i < 10)
	{
		printf("my turn\n");
		sleep(1);
	}
	return (NULL);
}

void *your_turn()
{
	int	i;

	i = -1;
	while(++i < 2)
	{
		printf("your turn\n");
		sleep(2);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t new;

	pthread_create(&new, NULL, my_turn, NULL);
	your_turn();
	pthread_join(new, NULL);
}