/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:24:02 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/22 16:57:47 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <pthread.h>
#include <stdio.h>

typedef struct num
{
	int			ttd;
	int 		tte;
	int			tts;
	int			n_eat;
	struct num	*next;
} t_num;

typedef struct forks
{
	int id;
	int	taken;
	struct forks	*next;
} t_fork;

typedef struct philosopher
{
	int	id;
	t_fork *lf;
	t_fork *rf;
	struct philosopher *next;
} t_philo;

void	*ft_memcpy(void *dst, void *src, size_t n);
t_philo	*new_philo(int id, t_fork *r, t_fork *l);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
t_philo	*new_fork(int id, int taken);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(char *s1);
int		ft_atoi(char *str);
size_t	ft_strlen(char *s);
int		ft_isdigit(int c);

#endif