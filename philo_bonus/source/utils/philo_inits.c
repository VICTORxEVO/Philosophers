#include "philo_bonus.h"

bool   eat(t_philo *philo)
{
    grap_forks(philo->ccu->forks);
    printt(philo, 'E');
    usleep_v2((size_t)philo->ccu->t_eat);
    sem_wait(philo->dead_l);
    philo->last_meal = get_time();
    sem_post(philo->dead_l);
    if (philo->ccu->n_meals != -1)
    {
        sem_wait(philo->meal_l);
        philo->meal++;
        sem_post(philo->meal_l);
    }
    return (true);
}

bool    sleep_think(t_philo *philo)
{
    sem_wait(philo->meal_l);
    if (philo->finished)
        return (sem_post(philo->meal_l), false);
    sem_post(philo->meal_l);
    printt(philo, 'S');
    usleep_v2((size_t)philo->ccu->t_sleep);
    printt(philo, 'T');
    return (true);
}




















void    init_philo_needs(t_philo *philo)
{
    philo->ccu->forks = open(FORKS_NAME, 0);
    if (philo->ccu->forks == SEM_FAILED)
        (puterr_msg(&philo->ccu->err, 's'), exit_v2(philo->ccu), exit(1));
    philo->ccu->print_l = open (PRINT_NAME, 0);
    if (philo->ccu->print_l == SEM_FAILED)
        (puterr_msg(&philo->ccu->err, 's'), exit_v2(philo->ccu), exit(2));
    philo->dead_l = open(DEAD_NAME, O_CREAT, 0644, 1);
    if (philo->dead_l == SEM_FAILED)
        (puterr_msg(&philo->ccu->err, 's'), exit_v2(philo->ccu), exit(3));
    if (philo->ccu->n_meals != -1)
    {
        philo->meal_l = open(MEAL_NAME, O_CREAT, 0644, 1);
        if (philo->meal_l == SEM_FAILED)
            (puterr_msg(&philo->ccu->err, 's'), exit_v2(philo->ccu), exit(4));
        philo->t_hunger = malloc(sizeof(pthread_t));
        if (!philo->t_parent)
            (puterr_msg(&philo->ccu->err, 'M'), exit_v2(philo->ccu), exit(5));
    }
    philo->t_parent = malloc(sizeof(pthread_t));
    if (!philo->t_parent)
        (puterr_msg(&philo->ccu->err, 'M'), exit_v2(philo->ccu), exit(6));
    pthread_create(philo->t_parent, NULL, philo_parent, philo);
}


void special_philo(t_philo *philo)
{
    if (philo->ccu->n_philo == 1)
        printt(philo, "R"), usleep_v2(philo->ccu->t_death + 100);
    if (!(philo->id % 2))
        usleep_v2(1);
}