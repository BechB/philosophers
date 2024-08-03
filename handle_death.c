/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:19:22 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/03 15:15:01 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    get_time(t_philo *philo)
{
    long ms;
    //     seconds  = end.tv_sec  - start.tv_sec;
//     useconds = end.tv_usec - start.tv_usec;

//     printf("Elapsed time: %f milliseconds\n", mtime);
}

void    *handle_death(void *philos)
{
    t_philo *philo = (t_philo *) philos;
    printf(RED"%ld\n"RESET, last_eat->tv_sec * 1000);
    
}

// int main() {
//     struct timeval start, end;
//     long seconds, useconds;
//     double mtime;

//     // Obtenir le temps de début
//     gettimeofday(&start, NULL);

//     // Effectuer une opération (exemple : boucle simple)
//     for (int i = 0; i < 1000000; i++);

//     // Obtenir le temps de fin
//     gettimeofday(&end, NULL);

//     // Calculer l'intervalle de temps
//     seconds  = end.tv_sec  - start.tv_sec;
//     useconds = end.tv_usec - start.tv_usec;

//     mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;

//     printf("Elapsed time: %f milliseconds\n", mtime);

//     return 0;
// }