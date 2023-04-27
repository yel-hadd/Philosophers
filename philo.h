/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:24:02 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/26 14:28:45 by yel-hadd         ###   ########.fr       */
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
	int					id;
	int					ttd;
	int					tte;
	int					tts;
	long				ms;
	int					n_meals;
	int					max_eat;
	long				last_eat;
	long				start_ts;
	t_fork 				*lf;
	t_fork 				*rf;
	struct philosopher	*next;
} t_philo;

typedef struct num
{
	int			n_phil;
	int			ttd;
	int			n_eat;
	int 		tte;
	int			tts;
	long		ms;
	t_philo		*p;
	t_philo		*current;
	t_fork		*f;
	struct num	*next;
} t_num;

t_num	*parse_params(char **arg, int arg_count, long time);
t_philo	*new_philo(t_num *n, int id, t_fork *r, t_fork *l);
void	parse_philos(t_num *n, t_fork **f, int n_phil);
void	philo_add_back(t_philo **lst, t_philo *new);
void	*ft_memcpy(void *dst, void *src, size_t n);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	fork_add_back(t_fork **lst, t_fork *new);
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


#endif