/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:58:08 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/18 19:01:05 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_eating(t_philo *philo)
{
	long	time;
	
	pthread_mutex_lock(&philo->forks[philo->right_fork]);
	pthread_mutex_lock(&philo->forks[philo->left_fork]);
	time = get_time(philo) - philo->go;
	pthread_mutex_lock(&philo->m_die);
	if (philo->death == 1)
	{
		pthread_mutex_unlock(&philo->m_die);
		pthread_mutex_unlock(&philo->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->forks[philo->right_fork]);
		return ;
	}
	pthread_mutex_unlock(&philo->m_die);
	printf("[%ld] |PHILO [%d] |has taken forks\n", time, philo->id);	
	printf(GREEN"[%ld] |PHILO [%d] |EATING\n"RESET, time, philo->id);
	pthread_mutex_lock(&philo->m_eat);
	philo->last_eat = get_time(philo);
	pthread_mutex_unlock(&philo->m_eat);
	ft_usleep(philo, philo->t_eat);
	philo->t_have_eat++;
	pthread_mutex_unlock(&philo->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->forks[philo->right_fork]);
	pthread_mutex_lock(&philo->finish_meal);
	if (philo->t_have_eat == philo->t_must_eat)
	{
		philo->finish_eat++;
		pthread_mutex_unlock(&philo->finish_meal);
		return ;
	}
	pthread_mutex_unlock(&philo->finish_meal);
	return ;
}

void    ft_sleeping(t_philo *philo)
{
	long	time;

	time = get_time(philo) - philo->go;
	pthread_mutex_lock(&philo->m_die);
	if (philo->death == 1)
	{
		pthread_mutex_unlock(&philo->m_die);
		return ;
	}
	pthread_mutex_unlock(&philo->m_die);
	printf(BLUE"[%ld] |PHILO [%d] |SLEEPING\n"RESET, time, philo->id);
	ft_usleep(philo, philo->t_sleep);
	return ;
}

void    ft_thinking(t_philo *philo)
{
	long	time;
	
	time = get_time(philo) - philo->go;
	pthread_mutex_lock(&philo->m_die);
	if (philo->death == 1)
	{
		pthread_mutex_unlock(&philo->m_die);
		return ;
	}
	pthread_mutex_unlock(&philo->m_die);
	printf(YELLOW"[%ld] |PHILO [%d] |THINKING\n"RESET, time, philo->id);
	return ;
}

void	ft_usleep(t_philo *philo, long arg)
{
	long	t;
	long	time;

	gettimeofday(&philo->time, NULL);
	time = (philo->time.tv_sec * 1000000) + (philo->time.tv_usec);
	while(1)
	{
		gettimeofday(&philo->time, NULL);
		t = (philo->time.tv_sec * 1000000) + (philo->time.tv_usec);
		if ((t - time) >= arg)
			return ;
		usleep(25);
	}
	return ;
}
