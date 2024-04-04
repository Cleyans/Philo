#ifndef PHILO_H
# define PHILO_H

/*
**************************************************************
*                         *INCLUDE*                          *
**************************************************************
*/

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdarg.h>

/*
**************************************************************
*                         *STRUCT*                           *
**************************************************************
*/

typedef struct s_philo
{
	int					id;
	int					last_meal;
	int					is_eating;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					number_of_meals;
	pthread_t			thread_id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_general	*general;
}						t_philo;

typedef struct s_prog
{
    int					number_of_philosophers;
    int					time_to_die;
    int					time_to_sleep;
    int					time_to_eat;
    int					number_of_meals;
    int					number_to_eat;
    int					start_time;
    int					philosopher_dead;
    pthread_mutex_t		*fork_mutex;
    pthread_mutex_t		mutex;
    pthread_mutex_t		*left_fork;
    pthread_mutex_t		*right_fork;
    t_philo				*philosophers;
}						t_prog;

/*
**************************************************************
*                         *FONCTIONS*                        *
**************************************************************
*/

void	ft_thread_create(t_prog *prog);
void	ft_mutex_create(t_prog *prog);
void	*routine(void *arguments);
void	test_printf(const char *format, ...);
int		get_time(void);
int		ft_init(int argc, char **argv, t_prog *prog);
int		init_philo(t_prog *prog);
int		verif_errors(char *av[]);
int		verif_ascii(char *av[]);
int		atoi_philo(char *str);

#endif
