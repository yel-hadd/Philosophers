/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:24:02 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/20 00:05:26 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <pthread.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *s);


#endif