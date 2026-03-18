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

t_philo	*init_philos(char **av)
{
	int		i;
	short int	nb_philos;
	t_philo		*philos;
	pthread_mutex_t	*forks;
	
	i = 0;
	nb_philos = atoi(av[1]);	
	philos = malloc(sizeof(t_philo) * nb_philos);
	forks = malloc(sizeof(pthread_mutex_t) * nb_philos);
	while (i < nb_philos)
	{
		philos[i].id = i;
		philos[i].nb_philos = nb_philos;
		pthread_mutex_init(&forks[i], NULL);
		philos[i].forks = forks;
		philos[i].time_to_die = atoi(av[2]);
		philos[i].time_to_eat = atoi(av[3]);
		philos[i].time_to_sleep = atoi(av[4]);
		philos[i].state = THINKING;
		i++;
	}
	return (philos);
}

int	main(int ac, char **av)
{
	t_philo		*philos;
	
	philos = NULL;
	if (!parsing(ac, av))
		return (0);	
	philos = init_philos(av);
	manage_thread(philos, philos[0].forks, philos[0].nb_philos);
	free(philos[0].forks);
	free(philos);
	return (0);
}
