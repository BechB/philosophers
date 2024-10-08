/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:54:28 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/24 18:09:05 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize( t_data *dta, char **argv)
{
	dta->nb_philo = ft_atoi(argv[1]);
	dta->t_die = ft_atoi(argv[2]) * 1000;
	dta->t_eat = ft_atoi(argv[3]) * 1000;
	dta->t_sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5])
		dta->t_must_eat = ft_atoi(argv[5]);
	else
		dta->t_must_eat = 0;
	dta->t_have_eat = 0;
	dta->philos = malloc(sizeof(t_philo) * dta->nb_philo);
	dta->finish_eat = 0;
	if (!dta->philos)
	{
		dta->error = 1;
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_data	*dta;

	dta = malloc(sizeof(t_data));
	dta->error = 0;
	parse_args(dta, argc, argv);
	if (dta->error == 0)
		parse_args2(dta, argc, argv);
	if (dta->error == 0)
		parse_args3(dta, argv);
	if (dta->error == 1)
	{
		free(dta->philos);
		free(dta);
		return (1);
	}
	initialize(dta, argv);
	handle_thread(dta);
	free(dta->philos);
	free(dta);
	return (0);
}
