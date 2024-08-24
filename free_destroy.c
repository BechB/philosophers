/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:59:20 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/24 18:12:42 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_and_destroy(t_data *dta)
{
	int	i;

	i = 0;
	while (i < dta->nb_philo)
	{
		pthread_mutex_destroy(&dta->philos->mutex[i]);
		pthread_mutex_destroy(&dta->philos[i].m_eat);
		pthread_mutex_destroy(&dta->philos[i].m_die);
		pthread_mutex_destroy(&dta->philos[i].finish_meal);
		i++;
	}
	free(dta->philos->mutex);
	free(dta->philos->philo_ids);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_die);
	if (philo->death == 1)
	{
		pthread_mutex_unlock(&philo->m_die);
		return (1);
	}
	pthread_mutex_unlock(&philo->m_die);
	return (0);
}
