#include "../header/philo.h"

time_t	elapsed_time(struct timeval start)
{
	struct timeval	end;
	time_t		elapsed;

	gettimeofday(&end, NULL);
	elapsed = (end.tv_sec - start.tv_sec) * 1000
		+ (end.tv_usec - start.tv_usec) / 1000;
	return (elapsed);
}
time_t	get_event(t_philo *philo)
{
	if (philo->state == EATING)
		return (philo->time_to_eat);
	else if (philo->state == SLEEPING)
		return (philo->time_to_sleep);
	else if (philo->state == DEAD)
		return (philo->time_to_die);
	else
		return (0);

}
short int	ft_event(struct timeval *st_death_evt, t_philo *philo)
{
	time_t		elapsed;
	time_t		evt_dur;
	struct timeval	start;

	elapsed = 0;
	evt_dur = get_event(philo);
	gettimeofday(&start, NULL);
	while (evt_dur - elapsed >= 0)
	{
		usleep(100);
		elapsed = elapsed_time(start);
		if (philo->state != EATING
			&& philo->time_to_die - elapsed_time(*st_death_evt) <= 0)
		{
			philo->state = DEAD;
			return (0);
		}
	}
	if (philo->state == EATING)
		gettimeofday(st_death_evt, NULL);
	return (1);
}

