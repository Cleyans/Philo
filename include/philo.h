/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brclemen <brclemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:59:47 by brclemen          #+#    #+#             */
/*   Updated: 2024/04/02 14:37:08 by brclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
*****************************************************
*                       INCLUDE                     *
*****************************************************
*/

# include <pthread.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>


/*
*****************************************************
*                       STRUCT                      *
*****************************************************
*/

typedef struct t_info
{
	int					p_id;
	int					philo_nb;
	int					die_time;
	int					eat_time;
	int					sleep_time;
	int					count_eating;
}						t_info;

typedef struct t_count
{
	int					count_mutex;
	int					count_thread;
	int					index_mutex;
	long long 			current;
	long int 			start;
}						t_count;

typedef struct t_philo
{
	struct timeval		current_time;
	t_count					count;
	t_info					info;
	pthread_mutex_t			*fork;
	pthread_t				*philo_t;
	
}						t_philo;

/*
*****************************************************
*                      FONCTIONS                    *
*****************************************************
*/

//	ROUTINE //

void	sleeping(t_philo philo);
void	eating(t_philo philo);
void	thinking(t_philo philo);

// PHILO //

void	init_philo_needs(char *av[], t_philo *philo);
void	print_philo(t_philo philo);
void	*routine(t_philo *philo);
void	creating_thread_and_mutex(t_philo *philo);
int		atoi_philo(char *str);
int		verif_ascii(char *av[]);
int		verif_errors(char *av[]);
long long	get_time(void);
void	ft_usleep(int ms);

#endif