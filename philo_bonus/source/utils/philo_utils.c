#include "philo_bonus.h"

void    init_philo_needs(t_philo *philo)
{
    philo->t_parent = malloc(sizeof(pthread_t));
	if (!philo->t_parent)
		(puterr_msg(&philo->ccu->err, 'M'), exit(1));
    philo->ccu->pd_l = sem_open(DEAD_SM, 0);
    if (philo->ccu->pd_l == SEM_FAILED)
        (puterr_msg(&philo->ccu->err, 's'), exit(2));
    if (pthread_create(philo->t_parent, (void *)0, philo_parent, philo) != 0)
        (puterr_msg(&philo->ccu->err, 'M'), exit(1));
    if (philo->ccu->n_meals != -1)
    {
        philo->t_hunger = malloc(sizeof(pthread_t));
        if (!philo->t_hunger)
            (puterr_msg(&philo->ccu->err, 'M'), exit_v2(philo->ccu), exit(1));
        philo->ccu->meal_l = sem_open(MEAL_SM, 0);
        if (philo->ccu->meal_l == SEM_FAILED)
            (puterr_msg(&philo->ccu->err, 's'), exit_v2(philo->ccu), exit(1));
        pthread_create(philo->t_hunger, NULL, philo_hunger, philo);
    }
}


void    special_philo(t_philo *philo)
{
    if (philo->ccu->n_philo == 1)
        (printt(philo, 'F'), usleep_v2(philo->ccu->t_death + 20), exit(1));
    if (!(philo->id % 2))
        usleep_v2(1);
}

bool   eat(t_philo *philo)
{
    grap_forks(philo);
    printt(philo, 'E');
    usleep_v2((size_t)philo->ccu->t_eat);
    LOCK(philo->ccu->pd_l);
    philo->last_meal = get_time();
    UNLOCK(philo->ccu->pd_l);
    if (philo->ccu->n_meals != -1)
    {
        LOCK(philo->ccu->meal_l);
        philo->meal++;
        UNLOCK(philo->ccu->meal_l);
    }
    down_forks(philo);
    return (true);
}

bool    sleep_think(t_philo *philo)
{
    if (philo->ccu->n_meals != -1)
    {
        LOCK(philo->ccu->meal_l);
        if (philo->finished)
            (UNLOCK(philo->ccu->meal_l), exit(0));
        UNLOCK(philo->ccu->meal_l);
    }
    printt(philo, 'S');
    usleep_v2((size_t)philo->ccu->t_sleep);
    printt(philo, 'T');
    return (true);
}