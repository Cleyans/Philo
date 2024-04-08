/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:12:41 by brclemen          #+#    #+#             */
/*   Updated: 2024/04/08 20:23:43 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_init(int ac, char **av, t_prog *prog)
{
	if (ac == 5 || ac == 6)
	{
		prog->number_of_philosophers = atoi_philo(av[1]);
		prog->time_to_eat = atoi_philo(av[2]);
		prog->time_to_die = atoi_philo(av[3]);
		prog->time_to_sleep = atoi_philo(av[4]);
		prog->fork_mutex = 0;
		prog->philosophers = 0;
		prog->philosophers = malloc(sizeof(pthread_mutex_t)
				* prog->number_of_philosophers);
		if (ac == 5)
			prog->number_to_eat = 0;
		else if (ac == 6)
			prog->number_to_eat = atoi_philo(av[5]);
		if (init_philo(prog) == 1)
			return (1);
		return (0);
	}
	return (0);
}
