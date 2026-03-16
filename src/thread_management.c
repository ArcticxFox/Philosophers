#include "../header/philo.h"


void	manage_thread(t_philo *philos, pthread_mutex_t *forks, int nb_max)
{
	int	i;

	i = 0;
	while (i < nb_max)
	{
		pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < nb_max)
		pthread_join(philos[i++].thread, NULL);
	i = 0;
	while (i < nb_max)
		pthread_mutex_destroy(&forks[i++]);

}
