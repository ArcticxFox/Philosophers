#include "../header/philo.h"

void	ft_lock(t_philo *philo, int left, int right)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->forks[right]);
		pthread_mutex_lock(&philo->forks[left]);
	}
	else
	{
		pthread_mutex_lock(&philo->forks[left]);
		pthread_mutex_lock(&philo->forks[right]);
	}
}

void	ft_unlock(t_philo *philo, int left, int right)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->forks[left]);
		pthread_mutex_unlock(&philo->forks[right]);
	}
	else
	{
		pthread_mutex_unlock(&philo->forks[right]);
		pthread_mutex_unlock(&philo->forks[left]);
	}
}

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
