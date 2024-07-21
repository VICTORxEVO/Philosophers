#include "philo_bonus.h"

int main(int ac, char *av[])
{
	t_all *ccu;
	int i;

	ccu = ft_calloc(1, sizeof(t_all));
    if (!ccu || !parser(ac, av, ccu) || !ccu_init(ccu))
		return (exit_v2(ccu));
	i = -1;
	while (++i < ccu->n_philo)
	{
		ccu->pids[i] = fork();
		if (ccu->pids[i]  < 0)
			return (puterr_msg(&ccu->err, 'f'), exit_v2(ccu));
		else if (ccu->pids[i] == CHILD)
			life(&ccu->philos[i]);
	}
	parent_action(ccu);
	return 0;
}
