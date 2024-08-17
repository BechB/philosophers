/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:58:08 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/14 01:08:14 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_eating(t_philo *philo)
{
	long	time;
	
	pthread_mutex_lock(&philo->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->forks[philo->right_fork]);
	time = get_time(philo) - philo->go;
	if (philo->death == 1)
		return ;
	printf("[%ld] |PHILO [%d] |has taken forks\n", time, philo->id);	
	printf(GREEN"[%ld] |PHILO [%d] |EATING\n"RESET, time, philo->id);
	ft_usleep(philo, philo->t_eat);
	philo->last_eat = get_time(philo);
	philo->t_have_eat++;
	pthread_mutex_unlock(&philo->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->forks[philo->left_fork]);
	if (philo->t_have_eat == philo->t_must_eat)
	{
		philo->finish_eat++;
		philo->t_have_eat = -1;
		return ;
	}
	return ;
}

void    ft_sleeping(t_philo *philo)
{
	long	time;

	time = get_time(philo) - philo->go;
	if (philo->death == 1)
		return ;
	printf(BLUE"[%ld] |PHILO [%d] |SLEEPING\n"RESET, time, philo->id);
	ft_usleep(philo, philo->t_sleep);
	return ;
}

void    ft_thinking(t_philo *philo)
{
	long	time;
	
	time = get_time(philo) - philo->go;
	if (philo->death == 1)
		return ;
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
