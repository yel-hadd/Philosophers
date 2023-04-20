/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:23:01 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/20 20:53:53 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *my_turn(void *arg)
{
	int	i;
	int	*ptr = (int *) arg;

	i = -1;
	while(++i < 10)
	{
		*ptr = i;
		printf("%d\n", *ptr);
		sleep(1);
	}
	return (ft_strdup("Hola\n"));
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

//char	*set_str()
//{
//	
//}

int	main(void)
{
	pthread_t new;
	int	i;
	char	*str;

	i = 0;
	pthread_create(&new, NULL, my_turn, &i);
	your_turn();
	pthread_join(new, (void *) &str);
	printf("---* %s\n", str);
	printf("---* %d\n", i);
}