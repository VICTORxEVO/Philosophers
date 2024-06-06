#include "philo.h"

int main(int ac, char *av[])
{
	t_all *ccu;
	if (!parser(ac, av, &ccu))
		return (exit_v2(ccu));
	return 0;
}
