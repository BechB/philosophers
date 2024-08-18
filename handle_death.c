/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:19:22 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/18 18:59:01 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *handle_death(void *philos)
{
	t_philo	*philo = (t_philo *) philos;
	long	current_time;
	int		i;
	long	time;

	while(1)
	{
		i = 0;
		while (i < philo->nb_philo)
		{
			pthread_mutex_lock(&philo->m_eat);
			if (philo->last_eat != 0)
			{
				pthread_mutex_unlock(&philo->m_eat);
				pthread_mutex_lock(&philo->finish_meal);
				if (philo->finish_eat == 1)
				{
					pthread_mutex_unlock(&philo->finish_meal);
					return (NULL);
				}
				pthread_mutex_unlock(&philo->finish_meal);
				current_time = get_time(philos);
				pthread_mutex_lock(&philo->m_eat);
				if (current_time - philo->last_eat > (philo->t_die / 1000))
				{
					pthread_mutex_unlock(&philo->m_eat);
					time = get_time(philo) - philo->go;
					printf(RED "[%ld] :PHILO [%d] IS DEAD\n" RESET, time, philo->id);
					i = 0;
					while (i < philo->nb_philo)
					{
						pthread_mutex_lock(&philo[i].m_die);
						philo[i].death = 1;
						pthread_mutex_unlock(&philo[i].m_die);
						i++;
					}
					return (NULL);
				}
				pthread_mutex_unlock(&philo->m_eat);
			}
			else
				pthread_mutex_unlock(&philo->m_eat);
			i++;
		}
	}
	return (NULL);
}

long    get_time(t_philo *philos)
{
	long	current_time;

	gettimeofday(&philos->time, NULL);
	current_time = (philos->time.tv_sec * 1000) + (philos->time.tv_usec / 1000);
	return (current_time);
}
