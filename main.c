/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:23:01 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/20 21:14:12 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define BIG 1000000000UL
uint32_t	counter = 0;
//char	*set_str()
//{
//	
//}

void	*incr_to_big_1(void *arg)
{
	uint32_t i = -1;
	pthread_mutex_t *lock;

	lock = (pthread_mutex_t *) arg;

	while(++i < BIG)
	{
		pthread_mutex_lock(lock);
		counter++;
		pthread_mutex_unlock(lock);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	t;
	pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;
	//int	i;
	//char	*str;

	pthread_create(&t, NULL, incr_to_big_1, &lock);
	incr_to_big_1((void *) &lock);
	pthread_join(t, NULL);
	printf("---* %d\n", counter);
}