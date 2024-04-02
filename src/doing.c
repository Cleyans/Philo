#include "../include/philo.h"

// call all three in the routine ??

//void	sleeping();
void    sleeping(t_philo philo)
{
    philo.count.current = get_time();
    printf("%lld Philo %d is sleeping.\n", philo.count.current - philo.count.start, philo.count.index_mutex);
    ft_usleep(philo.info.sleep_time);
}

//void	eating();
void    eating(t_philo philo)
{
    philo.count.current = get_time();
    printf("%lld Philo %d is eating.\n", philo.count.current - philo.count.start, philo.count.index_mutex);
    ft_usleep(philo.info.eat_time);
}

//void	thinking();
void    thinking(t_philo philo)
{
    philo.count.current = get_time();
    printf("%lld Philo %d is thinking.\n", philo.count.current - philo.count.start, philo.count.index_mutex);
}