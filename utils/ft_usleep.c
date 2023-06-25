/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:24:59 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/06/25 14:11:33 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_usleep(long tts)
{
	long	start;

	start = get_ms_ts(0);
	while (get_ms_ts(start) <= tts)
		usleep(100);
}