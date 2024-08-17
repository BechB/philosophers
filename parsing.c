/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:15:48 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/17 14:42:52 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_args(t_data *dta, int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while(++i < argc)
	{
		j = 0;
		if (argv[i][0] == '-')
		{
			printf(RED"PHILO: no negative number !\n" RESET);
			dta->error = 1;
			return ;
		}
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf(RED"No alpha in arguments please.\n"RESET);
				dta->error = 1;
				return ;
			}
			j++;
		}			
	}
}

void	parse_args2(t_data *dta, int argc, char **argv)
{
	if (argc < 5)
	{
		printf(RED "PHILO: not enough arguments.\n" RESET);
		dta->error = 1;	
	}
	else if (argc > 6)
	{
		printf(RED "PHILO: too many arguments.\n" RESET);
		dta->error = 1;
	}
	else if (ft_atoi(argv[1]) == 0)
	{
		printf(RED "PHILO: no found philosopher.\n" RESET);
		dta->error = 1;
	}
	else if (ft_atoi(argv[2]) == 0)
	{
		printf(RED "PHILO: it's impossible...\n" RESET);
		dta->error = 1;
	}
}

void	parse_args3(t_data *dta, int argc, char **argv)
{
	(void) argc;
	if (ft_atoi(argv[4]) == 0 || ft_atoi(argv[3]) == 0)
	{
		printf(RED "PHILO: it's impossible...\n" RESET);
		dta->error = 1;
	}
	else if (argv[5])
	{
		if (ft_atoi(argv[5]) == 0)
		{
			printf(RED "PHILO: let me eat please !\n" RESET);
			dta->error = 1;
		}
	}
}
