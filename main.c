/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadd <yel-hadd@mail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:24:45 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/06/25 17:24:35 by yel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*make_circular(t_philo *ptr)
{
	t_philo	*copy;
	t_philo	*head;

	copy = ptr;
	head = ptr;
	while (copy->next != NULL)
		copy = copy->next;
	copy->next = head;
	return (head);
}

int	check_args(char **args, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!is_all_digits(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_num	*n;

	if (ac < 5 || !check_args(av + 1, ac - 1))
		return (write(2, "ERROR\n", 6), 1);
	if (ac == 6 && ft_atoi(av[5]) == 0)
		return (0);
	n = NULL;
	n = parse_params(av, ac);
	if (!check_params(n))
		return (1);
	parse_forks(&n->f, n->n_phil);
	parse_philos(n, &n->f, n->n_phil);
	n->start_ts = get_ms_ts(0);
	start_threads(n);
	return (0);
}
