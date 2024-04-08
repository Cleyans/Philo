/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:12:37 by brclemen          #+#    #+#             */
/*   Updated: 2024/04/08 20:15:04 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_prog	prog;

	if (ac < 1 && ac <= 6 && verif_errors(av) == 0)
	{
		ft_init(ac, av, &prog);
		ft_thread_create(&prog);
		init_philo(&prog);
	}
	return (0);
}

int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	test_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
