/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:19:22 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/13 19:48:20 by bbousaad         ###   ########.fr       */
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
		while (i < philo[i].nb_philo)
		{
			if (philo->last_eat != 0)
			{
				current_time = get_time(philos);
				if (current_time - philo->last_eat > (philo->t_die / 1000))
				{
					pthread_mutex_lock(&philo->die);
					time = get_time(philo) - philo->go;
					printf(RED "[%ld] :PHILO [%d] IS DEAD\n" RESET, time, philo->id);
					i = 0;
					while (i < philo[i].nb_philo)
					{
						philo[i].death = 1;
						i++;
					}
					pthread_mutex_destroy(&philo->die);
					return (NULL);
				}
			}
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
