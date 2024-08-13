/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:54:28 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/13 19:31:03 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize( t_data *dta, char **argv)
{
	dta->nb_philo = ft_atoi(argv[1]);
	dta->t_die = ft_atoi(argv[2]) * 1000;
	dta->t_eat = ft_atoi(argv[3]) * 1000;
	dta->t_sleep = ft_atoi(argv[4]) * 1000;
	if(argv[5])
		dta->t_must_eat = ft_atoi(argv[5]);
	dta->t_have_eat = 0;
	dta->philos = malloc(sizeof(t_philo) * dta->nb_philo + 1);
	if (!dta->philos)
	{
		dta->error = 1;
		return ;
	}
	dta->philos->finish_eat = 0;
}

int	main(int argc, char **argv)
{
	t_data  *dta;

	dta = malloc(sizeof(t_data));
	dta->error = 0;
	parse_args(dta, argc, argv);
	if (dta->error == 0)
		parse_args2(dta, argc, argv);
	if (dta->error == 0)
		parse_args3(dta, argc, argv);
	if ((argc == 5 || argc == 6) && dta->error == 0)
		initialize(dta, argv);
	if (dta->nb_philo == 1)
	{
		printf("0 :PHILO 1 has taken a fork\n");
		usleep(dta->philos->t_die);
		printf(RED"%d :PHILO 1 is died\n"RESET, dta->philos->t_die / 1000);
		dta->philos->death = 1;
	}
	if (dta->error == 0 && dta->philos->death == 0)
		handle_thread(dta);
	else
		return (1);
	return (0);
}
