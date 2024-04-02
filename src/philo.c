/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:01:34 by brclemen          #+#    #+#             */
/*   Updated: 2024/04/02 15:12:46 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


// NB PHILO, DIE TIME, EAT TIME, SLEEP TIME, NB EAT

// eat , think, sleep can do only one at once 
// forks as many as philosophers 
// once the philosopher have eaten he put back his fork and the other one that he used and sleep
// when they're awake again they start thinking again
// if he didn/t eat he dies
// all of them should eat and not died
// they can't speak to each other
// They don't know if one of them is about to die

// ARGS : number_of_philosophers/fork, time_to_die(millisecondes), time_to_eat(milliseconds), time_to_sleep(milliseconds), number_of_times_each_philosopher_must_eat.

// pair et impaire, tout les pairs mange en meme temps et tout les impaires mange en meme temps

int main(int ac, char *av[])
{
	if (ac >= 5 && ac <= 6 && verif_errors(av) == 0)
    {
		t_philo philo;
		philo.count.start = get_time();
		init_philo_needs(av, &philo);
		creating_thread_and_mutex(&philo);
		print_philo(philo);
	}
	return (0);
}

void	*routine(t_philo *philo)
{
	sleeping(*philo);
	eating(*philo);
	thinking(*philo);
	philo->count.count_thread++;
	return (NULL);
}

void	creating_thread_and_mutex(t_philo *philo)
{
	int i;
	int index;

	index = 0;
	i = philo->info.philo_nb;
	while (index < i)
	{
		philo->count.index_mutex = index;
		pthread_create(&philo->philo_t[index], NULL, (void *)&routine, philo);
		pthread_join(philo->philo_t[index], NULL);
		pthread_mutex_init(&philo->fork[index], NULL);
		index++;
	}
}

void	init_philo_needs(char *av[], t_philo *philo)
{
	philo->count.count_thread = 0;
	philo->info.philo_nb = atoi_philo(av[1]);
	philo->info.die_time = atoi_philo(av[2]);
	philo->info.sleep_time = atoi_philo(av[3]);
	philo->info.eat_time = atoi_philo(av[4]);
	if (av[5])
		philo->info.count_eating = atoi_philo(av[5]);
	else
		philo->info.count_eating = -1;
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->info.philo_nb);
	philo->philo_t = malloc(sizeof(pthread_t) * philo->info.philo_nb);
}

void	print_philo(t_philo philo)
{
	printf("Nombre de philo %d\n", philo.info.philo_nb);
	printf("Temps avant de mourir %d\n", philo.info.die_time);
	printf("Temps avant de dormir %d\n", philo.info.sleep_time);
	printf("Temps avant de manger %d\n", philo.info.eat_time);
	printf("Nombre de fois que les philos doivent manger %d\n", philo.info.count_eating);
}