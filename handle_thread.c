/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 01:41:58 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/04 18:50:38 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *ft_routine(void *philos)
{
	t_philo *philo = (t_philo *) philos;
	if (philo->t_have_eat != -1)
		ft_eating(philo);
	if (philo->finish_eat == 1)
		return (NULL);
	ft_sleeping(philo);
	ft_thinking(philo);
	return (NULL);
}

void    init_philo(t_data *dta, int i)
{
	dta->philos[i].id = i + 1;
	dta->philos[i].nb_philo = dta->nb_philo;
	dta->philos[i].t_die = dta->t_die;
	dta->philos[i].t_eat = dta->t_eat;
	dta->philos[i].t_sleep = dta->t_sleep;
	dta->philos[i].t_must_eat = dta->t_must_eat;
	dta->philos[i].eat.tv_usec = dta->philos->last_eat.tv_usec;
	if (dta->philos[i].id == dta->nb_philo)
		dta->philos[i].right_fork = 0;
	else
		dta->philos[i].right_fork = dta->philos[i].id;
	dta->philos[i].left_fork = dta->philos[i].id - 1;
	
}

void	handle_thread(t_data *dta)
{
	int i;
	pthread_t   	*philo_ids;
	pthread_t		checker;
	pthread_mutex_t *mutex;

	i = 0;
	mutex = malloc((sizeof(pthread_mutex_t)) * dta->nb_philo);
	philo_ids = malloc(sizeof(pthread_t) * dta->nb_philo);
	//checker = malloc(sizeof(pthread_t) * dta->nb_philo);
	while (i < dta->nb_philo)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	i = 0;
	while (i < dta->nb_philo)
	{
		init_philo(dta, i);
		dta->philos[i].forks = mutex;
		pthread_create(&philo_ids[i] , NULL, ft_routine, (void *) &dta->philos[i]);
		i++;
	}
	pthread_create(&checker, NULL, handle_death, (void *) &dta->philos);
	i = 0;
	while (i < dta->nb_philo)
	{
		pthread_join(philo_ids[i], NULL);
		pthread_join(checker, NULL);
		i++;
	}
	i = 0;
	while (i < dta->nb_philo)
	{
		pthread_mutex_destroy(&dta->philos->forks[i]);
		i++;
	}
}

void     handl_thread2(t_data *dta)
{
	(void) dta;
}
