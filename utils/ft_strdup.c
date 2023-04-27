/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:45:42 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/20 00:05:44 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = ft_calloc((len + 1), sizeof(char));
	if (!s2)
		return (0);
	ft_memcpy(s2, (void *) s1, ((len + 1) * sizeof(char)));
	return (s2);
}
