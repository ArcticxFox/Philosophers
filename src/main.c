#include "../header/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->forks[philo->id]);

	printf("Philo %d took fork\n", philo->id);
	if (philo->state == THINKING)
		printf("\t- Philo is Thinking\n");
	if (philo->state == SLEEPING)
		printf("\t- Philo is Sleeping\n");
	if (philo->state == EATING)
		printf("\t- Philo is Eating\n");
	pthread_mutex_unlock(&philo->forks[philo->id]);
	return NULL;
}

int	main(void)
{
	int		i = 0;
	int		nb_of_philos = 10;
	t_philo		*philos;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * nb_of_philos);
	while (i < nb_of_philos)
		pthread_mutex_init(&forks[i++], NULL);
	i = 0;
	philos = malloc(sizeof(t_philo) * nb_of_philos);
	while (i < nb_of_philos)
	{
		philos[i].state = THINKING;
		philos[i].id = i;
		philos[i].nb_philo = nb_of_philos;
		philos[i].forks = forks;
		if (i % 2 == 0)
			philos[i].state = SLEEPING;
		if (i % 3 == 0)
			philos[i].state = EATING;
		i++;
	}
	i = 0;
	while (i < nb_of_philos)
	{
		pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < nb_of_philos)
		pthread_join(philos[i++].thread, NULL);
	i = 0;
	while (i < nb_of_philos)
		pthread_mutex_destroy(&forks[i++]);
	free(forks);
	free(philos);
	return (0);
}
