#include "philo_bonus.h"

void    usleep_v2(size_t ms)
{
    size_t  start;

    start = get_time();
    while (get_time() - start < ms)
        usleep_v2(500);
}