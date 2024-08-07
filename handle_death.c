/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:19:22 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/07 15:02:52 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void    *handle_death(void *philos)
{
    t_philo *philo = (t_philo *) philos;
    int death;
    int sec;

    death = 0;
    sec = 0;
    gettimeofday(&philo->time, NULL);
    printf("Le philo %d a manger a fini a %ld,%ld ms\n", philo->id, philo->start.tv_sec, (philo->start.tv_usec));
    printf("Actuellement il est %ld,%ld\n", philo->time.tv_sec, philo->time.tv_usec);
    sec = philo->time.tv_sec - philo->start.tv_sec;
    if (sec == 0)
    {
        death = (philo->time.tv_usec / 1000) - (philo->start.tv_usec / 1000);
        printf(RED"DEATH %d\n"RESET, death);
    }
    if (death > philo->t_die)
        philo->death = 1;
    return (NULL);
}
