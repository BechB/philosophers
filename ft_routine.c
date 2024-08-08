/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 04:58:08 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/08 20:13:16 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_eating(t_philo *philo)
{
	
	if (philo->id % 2 == 0 && philo->nb_philo % 2 != 0)
        usleep(50);
	pthread_mutex_lock(&philo->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->forks[philo->right_fork]);
	printf(GREEN"PHILO %d: EATING \n"RESET, philo->id);
	philo->start = get_time(philo);
	usleep(philo->t_eat);
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
	(void) philo;
	printf(BLUE"PHILO %d: SLEEPING\n"RESET, philo->id);
	usleep(philo->t_sleep);
	return ; 
}

void    ft_thinking(t_philo *philo)
{
	(void) philo;
	printf(YELLOW"PHILO %d: THINKING\n"RESET, philo->id);
	return ;
}

void    ft_died(t_philo *philo)
{
	(void) philo;
	printf(RED"PHILO %d: EST MORT\n"RESET, philo->id);
	return ;
}
