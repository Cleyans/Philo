/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:12:44 by brclemen          #+#    #+#             */
/*   Updated: 2024/04/08 20:23:56 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	verif_errors(char *av[])
{
	if (verif_ascii(av) == -1)
	{
		printf("Error\n");
		return (-1);
	}
	if (atoi_philo(av[1]) > 200)
	{
		printf("Error\n");
		return (-1);
	}
	return (0);
}

int	verif_ascii(char *av[])
{
	int	args;
	int	index;

	args = 1;
	index = 0;
	while (av[args])
	{
		while (av[args][index])
		{
			if (!(av[args][index] <= '9' && av[args][index] >= '0'))
				return (-1);
			index++;
		}
		args++;
	}
	return (0);
}

// long long	get_time(void)
// {
// 	struct timeval    tv;

// 	gettimeofday(&tv, NULL);
// 	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
// }

// void	ft_usleep(int ms)
// {
// 	long int    time;

// 	time = get_time();
// 	while (get_time() - time < ms)
//         usleep(ms / 10);
// }