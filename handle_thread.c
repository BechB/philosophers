/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 01:41:58 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/24 18:08:30 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	lock_unlock(t_philo *philo)
{
	pthread_mutex_lock(&philo->finish_meal);
	if (philo->finish_eat == 1)
	{
		pthread_mutex_unlock(&philo->finish_meal);
		return (1);
	}
	pthread_mutex_unlock(&philo->finish_meal);
	pthread_mutex_lock(&philo->m_die);
	if (philo->death == 1)
	{
		pthread_mutex_unlock(&philo->m_die);
		return (1);
	}
	pthread_mutex_unlock(&philo->m_die);
	return (0);
}

void	*ft_routine(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *) philos;
	if (one_philo(philo) == 1)
		return (NULL);
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (lock_unlock(philo) == 1)
			return (NULL);
		ft_eating(philo);
		if (lock_unlock(philo) == 1)
			return (NULL);
		ft_sleeping(philo);
		if (lock_unlock(philo) == 1)
			return (NULL);
		ft_thinking(philo);
		if (lock_unlock(philo) == 1)
			return (NULL);
	}
	return (NULL);
}

void	init_philo(t_data *dta, int i)
{
	dta->philos[i].id = i + 1;
	dta->philos[i].death = 0;
	dta->philos[i].finish_eat = 0;
	dta->philos[i].t_have_eat = 0;
	dta->philos[i].last_eat = 0;
	dta->philos[i].nb_philo = dta->nb_philo;
	dta->philos[i].t_die = dta->t_die;
	dta->philos[i].t_eat = dta->t_eat;
	dta->philos[i].t_sleep = dta->t_sleep;
	dta->philos[i].t_must_eat = dta->t_must_eat;
	dta->philos[i].go = dta->philos->go;
	dta->philos[i].last_eat = dta->philos->last_eat;
	if (dta->philos[i].id == dta->nb_philo)
		dta->philos[i].right_fork = 0;
	else
		dta->philos[i].right_fork = dta->philos[i].id;
	dta->philos[i].left_fork = dta->philos[i].id - 1;
	pthread_mutex_init(&dta->philos[i].m_die, NULL);
	pthread_mutex_init(&dta->philos[i].m_eat, NULL);
	pthread_mutex_init(&dta->philos[i].finish_meal, NULL);
}

void	join_and_destroy(t_data *dta, pthread_t *philo_ids)
{
	int			i;
	pthread_t	checker;

	i = 0;
	if (dta->nb_philo > 1)
		pthread_create(&checker, NULL, handle_death, (void *)dta->philos);
	i = -1;
	while (++i < dta->nb_philo)
		pthread_join(philo_ids[i], NULL);
	if (dta->nb_philo > 1)
		pthread_join(checker, NULL);
	i = -1;
	while (++i < dta->nb_philo)
		pthread_mutex_destroy(&dta->philos->forks[i]);
	return ;
}

void	handle_thread(t_data *dta)
{
	int	i;

	dta->philos->death = 0;
	dta->philos->mutex = malloc((sizeof(pthread_mutex_t)) * dta->nb_philo);
	dta->philos->philo_ids = malloc(sizeof(pthread_t) * dta->nb_philo);
	i = -1;
	while (++i < dta->nb_philo)
		pthread_mutex_init(&dta->philos->mutex[i], NULL);
	i = -1;
	dta->philos->go = get_time(dta->philos);
	while (++i < dta->nb_philo)
	{
		init_philo(dta, i);
		dta->philos[i].forks = dta->philos->mutex;
	}
	i = -1;
	while (++i < dta->nb_philo)
	{
		pthread_create(&dta->philos->philo_ids[i], NULL,
			ft_routine, (void *) &dta->philos[i]);
	}
	join_and_destroy(dta, dta->philos->philo_ids);
	free_and_destroy(dta);
	return ;
}
