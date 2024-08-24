/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:19:22 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/24 18:09:21 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philos_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->finish_meal);
	if (philo->finish_eat == 1)
	{
		pthread_mutex_unlock(&philo->finish_meal);
		return (1);
	}
	pthread_mutex_unlock(&philo->finish_meal);
	return (0);
}

int	handle_death2(t_philo *philo, int i)
{
	long	current_time;
	long	time;

	time = 0;
	current_time = get_time(philo);
	pthread_mutex_lock(&philo->m_eat);
	if (current_time - philo->last_eat > (philo->t_die / 1000))
	{
		pthread_mutex_unlock(&philo->m_eat);
		i = 0;
		time = get_time(philo) - philo->go;
		printf(RED "[%ld] :PHILO [%d] IS DEAD\n" RESET, time, philo->id);
		while (i < philo->nb_philo)
		{
			pthread_mutex_lock(&philo[i].m_die);
			philo[i].death = 1;
			pthread_mutex_unlock(&philo[i].m_die);
			i++;
		}
		return (1);
	}
	pthread_mutex_unlock(&philo->m_eat);
	return (0);
}

void	*handle_death(void *philos)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *) philos;
	while (1)
	{
		i = 0;
		while (i < philo->nb_philo)
		{
			pthread_mutex_lock(&philo->m_eat);
			if (philo->last_eat != 0)
			{
				pthread_mutex_unlock(&philo->m_eat);
				if (check_philos_eat(philo) == 1)
					return (NULL);
				if (handle_death2(philo, i) == 1)
					return (NULL);
			}
			else
				pthread_mutex_unlock(&philo->m_eat);
			i++;
		}
	}
	return (NULL);
}

long	get_time(t_philo *philos)
{
	long	current_time;

	gettimeofday(&philos->time, NULL);
	current_time = (philos->time.tv_sec * 1000) + (philos->time.tv_usec / 1000);
	return (current_time);
}
