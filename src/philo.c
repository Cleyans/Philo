/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:01:34 by brclemen          #+#    #+#             */
/*   Updated: 2024/04/01 14:30:25 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>
#include <stdlib.h>

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
	if (ac > 1)s
    {
		t_philo philo;

		init_philo_needs(av, &philo);
		print_philo(philo);
	}
	return (0);
}

void	init_philo_needs(char *av[], t_philo *philo)
{
	philo->philo_nb = atoi_philo(av[1]);
	philo->die_time = atoi_philo(av[2]);
	philo->sleep_time = atoi_philo(av[3]);
	philo->eat_time = atoi_philo(av[4]);
	if (av[5])
		philo->count_eating = atoi_philo(av[5]);
	else
		philo->count_eating = 0;
}

void	print_philo(t_philo philo)
{
	printf("Nombre de philo %d\n", philo.philo_nb);
	printf("Temps avant de mourir %d\n", philo.die_time);
	printf("Temps avant de dormir %d\n", philo.sleep_time);
	printf("Temps avant de manger %d\n", philo.eat_time);
	printf("Nombre de fois que les philos doivent manger %d\n", philo.count_eating);
}