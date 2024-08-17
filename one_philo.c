/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:45:11 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/17 14:54:43 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    one_philo(t_philo *philo)
{
    if (philo->nb_philo == 1)
	{
		printf("0 :PHILO 1 has taken a fork\n");
		ft_usleep(philo, philo->t_die);
		printf(RED"%d :PHILO 1 is died\n"RESET, (philo->t_die / 1000) + 1);
		return (1);
	}
    return (0);
}