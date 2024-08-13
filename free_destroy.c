/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:59:20 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/11 22:07:50 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    free_and_destroy(t_data *dta)
{
    int i;

    i = 0;
    while(&dta->philos[i])
    {
        free(&dta->philos[i]);
        i++;
    }
}