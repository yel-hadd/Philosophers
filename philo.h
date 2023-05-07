/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:24:02 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/30 17:50:20 by yel-hadd         ###   ########.fr       */
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

# define EAT	0
# define SLEEP	1
# define DEAD	

struct timeval tv;

typedef __darwin_suseconds_t msecond;

typedef	struct num t_num;
typedef	struct philosopher t_philo;
typedef struct forks t_forks;

typedef struct forks
{
	int				id;
	int				taken;
	pthread_mutex_t	*lock;
	struct forks	*next;
} t_fork;

struct philosopher
{
	int					id;
	int					n_meals;
	long				last_eat;
	pthread_t			*thrd;
	t_fork 				*lf;
	t_fork 				*rf;
	t_num				*args;
	t_philo				*next;
};

struct num
{
	int				n_phil;
	int				ttd;
	int				max_eat;
	int 			tte;
	int				tts;
	t_philo			*p;
	long			start_ts;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*plock;
	t_fork			*f;
	t_num			*next;
};

t_num	*parse_params(char **arg, int arg_count, long time);
void	parse_philos(t_num *n, t_fork **f, int n_phil);
void	philo_add_back(t_philo **lst, t_philo *new);
void	*ft_memcpy(void *dst, void *src, size_t n);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	fork_add_back(t_fork **lst, t_fork *new);
t_philo	*new_philo(int id, t_fork *r, t_fork *l);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	parse_forks(t_fork **f, int n_phil);
t_fork	*new_fork(int id, int taken);
void	ft_bzero(void *s, size_t n);
int		check_params(t_num *no);
char	*ft_strdup(char *s1);
int		ft_atoi(char *str);
size_t	ft_strlen(char *s);
int		ft_isdigit(int c);
long 	get_ms_ts(long subtract);
void    *routine(void *ptr);




#endif