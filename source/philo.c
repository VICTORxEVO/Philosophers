#include "philo.h"

int main(int ac, char *av[])
{
	t_all *ccu;

	ccu = ft_calloc(1, sizeof(t_all));
    if (!ccu || !parser(ac, av, ccu) || !ccu_init(ccu))
		return (exit_v2(ccu));
	
	return 0;
}
