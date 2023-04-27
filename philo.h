/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:24:02 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/27 16:21:32 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
#include <stdio.h>

struct timeval tv;

typedef __darwin_suseconds_t msecond;

typedef struct forks
{
	int				id;
	int				taken;
	pthread_mutex_t	lock;
	struct forks	*next;
} t_fork;

typedef struct philosopher
{
} t_philo;

typedef struct num
{
} t_num;

#endif