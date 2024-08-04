/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:19:22 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/04 19:31:41 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void    *handle_death(void *philos)
{
    t_philo *philo = (t_philo *) philos;
    int death;

    death = 0;
    gettimeofday(&philo->time, NULL);
    printf("Le philo %d a manger a %ld ms\n", philo->id, philo->last_eat.tv_usec / 1000);
    printf("et il est %ld ms\n", philo->time.tv_usec / 1000);
    death = (philo->last_eat.tv_usec / 1000) + (philo->t_eat / 1000);
    //death = death - (philo->t_die / 1000);
    printf("DEATH = %d\n", death);
    return (NULL);
}
