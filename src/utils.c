#include "../include/philo.h"

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