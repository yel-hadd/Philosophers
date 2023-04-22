/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:24:45 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/04/22 17:16:30 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_add_back(t_fork **lst, t_fork *new)
{
	t_fork	*temp;

	temp = *lst;
	if (!temp)
		*lst = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

//t_fork  *parse_forks(int num, char **arg)
//{
//	int		i;
//	t_fork	*f;
//	
//
//	i = 0;
//
//	while (i)
//	{
//		fork_add_back(&f, new_fork(ft_atoi(arg[1]), 0));
//	}
//}

int	check_params(t_num *no)
{
	if (no->ttd == -1 || no->tte == -1)
		return (0);
	if (no->tts == -1 || no->n_eat == -1)
		return (0);
	return (1);
}

t_num	*parse_params(char **arg, int arg_count)
{
	t_num	*node;

	node = (t_num *)malloc(sizeof(t_num));
	if (!node)
		return (node);
	node->ttd = ft_atoi(arg[1]);
	node->tte = ft_atoi(arg[2]);
	node->tts = ft_atoi(arg[3]);
	node->n_eat = -2;
	if (arg_count == 5)
		node->n_eat = ft_atoi(arg[4]);
	node->next = NULL;
	return (node);
}

int main(int ac, char **av)
{
	t_num	*n;

	n = parse_params(av, ac);
	if (!check_params(n))
		return (1);
	printf("%d\n", n->n_eat);
	return (0);
}
