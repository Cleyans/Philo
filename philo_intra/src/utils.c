#include "../include/philo.h"

void    ft_thread_create(t_prog *prog)
{
    int i;
    i = 0;
    prog->start_time = get_time();
    while (i < prog->number_of_philosophers)
    {
        pthread_create(&prog->philosophers[i].thread_id,
            NULL, &routine, (void *)&prog->philosophers[i]);
        pthread_join(prog->philosophers[i].thread_id, NULL);
        i++;
    }
}

void ft_mutex_create(t_prog *prog)
{
    int i;
    i = -1;
    prog->fork_mutex
        = malloc(sizeof(pthread_mutex_t) * prog->number_of_philosophers);
    if (!prog->fork_mutex)
        return ;
    while (++i < prog->number_of_philosophers)
        pthread_mutex_init(&prog->fork_mutex[i], NULL);
    pthread_mutex_init(&prog->mutex, NULL);
}

int init_philo(t_prog *prog)
{
    int i;
    i = 0;
    prog->philosophers = malloc(sizeof(t_philo)
            * prog->number_of_philosophers);
    if (!prog->philosophers)
        return (1);
    while (i < prog->number_of_philosophers)
    {
        prog->philosophers[i].id = i + 1;
        prog->philosophers[i].left_fork = &prog->fork_mutex[i];
        prog->philosophers[i].right_fork = &prog->fork_mutex[i + 1];
        prog->philosophers[i].time_to_die = prog->time_to_die;
        prog->philosophers[i].time_to_eat = prog->time_to_eat;
        prog->philosophers[i].time_to_sleep = prog->time_to_sleep;
        prog->philosophers[i].last_meal = 0;
        prog->philosophers[i].is_eating = 0;
        prog->philosophers[i].number_of_meals = 0;
        i++;
    }
    return(0);
}

void    *routine(void *arguments)
{
    t_philo *philosophers;
    philosophers = (t_philo *)arguments;
    test_printf("Philosophe %d   %d\n", philosophers->id, philosophers->time_to_die);
    return (0);
}

int atoi_philo(char *str)
{
    int sign;
    int result;

    sign = 1;
    result = 0;
    while (*str == ' ' || *str == '\t')
        str++;
    if (*str == '-')
        sign = -1;
    if(*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (result * sign);
}