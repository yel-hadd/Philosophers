/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:24:45 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/24 21:22:59 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
*/

void	take_fork(t_fork *f)
{
	
	
}

int main(int ac, char **av)
{
	t_num	*n;
	t_fork	*fork;
	struct	timeval	time;

	gettimeofday(&tv, NULL);
	n = NULL;
	fork = NULL;
	n = parse_params(av, ac, time.tv_sec);
	if (!check_params(n))
		return (1);
	parse_forks(&n->f, n->n_phil);
	parse_philos(n, &n->f, n->n_phil);
	return (0);
}


/*
void *philosopher(void *arg)
{
	int id = *(int*)arg; // get the philosopher's ID from the argument
	int left = id; // the left fork is the philosopher's ID
	int right = (id+1) % N; // the right fork is the next philosopher's ID
	while(1) // loop forever
	{
		printf("Philosopher %d is thinking\n", id); // print a message indicating that the philosopher is thinking
		sleep(rand()%3); // sleep for a random amount of time to simulate thinking
		sem_wait(&mutex); // acquire the mutex semaphore to prevent other philosophers from accessing the forks
		sem_wait(&forks[left]); // acquire the semaphore for the left fork
		sem_wait(&forks[right]); // acquire the semaphore for the right fork
		printf("Philosopher %d is eating\n", id); // print a message indicating that the philosopher is eating
		sleep(rand()%3); // sleep for a random amount of time to simulate eating
		sem_post(&forks[right]); // release the semaphore for the right fork
		sem_post(&forks[left]); // release the semaphore for the left fork
		sem_post(&mutex); // release the mutex semaphore
	}
	return NULL; // this line will never be reached, but we need to return something
}
*/