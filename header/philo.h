#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum	e_state
{
	DEAD = 1,
	EATING,
	SLEEPING,
	THINKING
}	t_state;

typedef struct	s_philo
{
	short int		id;
	short int		nb_philos;
	short int		*end_simulation;
	pthread_t		thread;
	pthread_mutex_t	*forks;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	t_state			state;
}	t_philo;

int			parsing(int ac, char **av);

void		ft_lock(t_philo *philo, int left, int right);
void		ft_unlock(t_philo *philo, int left, int right);
void		manage_thread(t_philo *philos, pthread_mutex_t *forks, int nb_max);

void		*philo_routine(void *arg);

time_t		elapsed_time(struct timeval start);
short int	ft_event(struct timeval *st_death_evt, t_philo *philo);


int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);

#endif
