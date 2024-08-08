/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:19:22 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/08 22:05:04 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *handle_death(void *philos)
{
    t_philo *philo = (t_philo *) philos;
    long    current_time;
    if (philo->last_eat <= 0)
        return (NULL);     
    current_time = get_time(philos);
    //printf("le philo %d a fini de manger a %ld, il est %ld\n", philo->id, philo->last_eat, current_time);
    //printf("diff : %ld\n", current_time - philo->last_eat);
    if (current_time - philo->last_eat > (philo->t_die / 1000))
    {
        printf(RED "PHILO %d IS DEAD\n" RESET, philo->id);
        exit (1);
    }
    return (NULL);
}

long    get_time(t_philo *philos)
{
    long    current_time;

    gettimeofday(&philos->time, NULL);
    current_time = (philos->time.tv_sec * 1000) + (philos->time.tv_usec / 1000);
    return (current_time);
}
