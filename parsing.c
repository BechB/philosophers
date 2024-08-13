/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:15:48 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/13 19:23:41 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_args(t_data *dta, int argc, char **argv)
{
	int	i;
	int	j;
	int len_arg;

	i = 1;
	j = 0;
	len_arg = 0;
	while(i < argc)
	{
		len_arg = len_read(argv, i);
		while (j < len_arg)
		{
			if (((argv[i][j] <= 'z') && (argv[i][j] >= 'a'))
				|| ((argv[i][j] <= 'Z') && (argv[i][j] >= 'A')))
			{
				printf("%c\n", argv[i][j]);
				printf("%d\n", i);
				printf("%d\n", j);
				printf(RED"PHILO: all argument must be digit\n" RESET);
				dta->error = 1;
				return ;
			}
			j++;
		}
		if (argv[i][0] == '-' && dta->error == 0)
		{
			printf(RED"PHILO: no negative number !\n" RESET);
			dta->error = 1;
		}
		i++;
	}
}

void	parse_args2(t_data *dta, int argc, char **argv)
{
	(void) argc;
	if (argc < 5)
	{
		printf(RED "PHILO: not enough arguments\n" RESET);
		dta->error = 1;	
	}
	else if (argc > 6)
	{
		printf(RED "PHILO: too many arguments\n" RESET);
		dta->error = 1;
	}
	else if (ft_atoi(argv[1]) == 0)
	{
		printf(RED "PHILO: no found infoosopher\n" RESET);
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
