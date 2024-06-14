#include "philo.h"

void    printt(t_philo *philo, char flag)
{
    char    *action;

    if (flag == 'E')
        action = "is eating";
    else if (flag == 'S')
        action = "is sleeping";
    else if (flag == 'T')
        action = "is thinking";
    else if (flag == 'D')
        action = "died";
    printf("%zu\t%d  %s\n", get_curr_time(philo), philo->id + 1, action);
}