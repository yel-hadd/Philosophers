/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:24:02 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/06/25 19:07:19 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_num				t_num;
typedef struct s_philosopher		t_philo;
typedef struct s_forks				t_forks;

typedef struct s_forks
{
	int							id;
	pthread_mutex_t				*lock;
	struct s_forks				*next;
}								t_fork;

struct							s_philosopher
{
	int							id;
	int							n_meals;
	long						last_eat;
	pthread_t					*thrd;
	t_fork						*lf;
	t_fork						*rf;
	t_num						*args;
	t_philo						*next;
};

struct							s_num
{
	int							n_phil;
	int							ttd;
	int							max_eat;
	int							tte;
	int							tts;
	t_philo						*p;
	long						start_ts;
	pthread_mutex_t				*lock;
	pthread_mutex_t				*plock;
	t_fork						*f;
	t_num						*next;
};

t_num	*parse_params(char **arg, int arg_count);
void	parse_philos(t_num *n, t_fork **f, int n_phil);
void	philo_add_back(t_philo **lst, t_philo *new);
void	*ft_memcpy(void *dst, void *src, size_t n);
t_philo	*new_philo(int id, t_fork *r, t_fork *l);
t_philo	*start_sleeping(t_philo *m, t_num *args);
t_philo	*start_thinking(t_philo *m, t_num *args);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	fork_add_back(t_fork **lst, t_fork *new);
t_philo	*start_eating(t_philo *m, t_num *args);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	parse_forks(t_fork **f, int n_phil);
void	ft_bzero(void *s, size_t n);
void	put_down_forks(t_philo *m);
t_philo	*pickup_forks(t_philo *m);
long	get_ms_ts(long subtract);
long	get_ms_ts(long subtract);
int		check_params(t_num *no);
void	start_threads(t_num *n);
void	join_threads(t_num *n);
char	*ft_strdup(char *s1);
void	*routine(void *ptr);
void	ft_usleep(long tts);
size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
t_fork	*new_fork(int id);
int		ft_isdigit(int c);
void	ft_sleep(long tts);
t_philo	*make_circular(t_philo *ptr);
void	*check_death(t_philo *philos, t_num *args);
int		is_all_digits(char *s);
void	free_all(t_num *head);

#endif