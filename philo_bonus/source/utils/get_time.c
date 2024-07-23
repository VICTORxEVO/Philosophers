#include "philo_bonus.h"

size_t  get_time(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000LL) + (time.tv_usec / 1000LL));
}

size_t  get_curr_time(t_philo *philo)
{
    size_t time;

    time = get_time() - philo->ccu->creation_t;
    return (time);
}