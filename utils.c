/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:16:42 by bbousaad          #+#    #+#             */
/*   Updated: 2024/07/27 21:59:26 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int				res;
	int				s;
	int				d;

	d = 0;
	res = 0;
	s = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (str[d] >= 48 && str[d] <= 57)
	{
		res = (res * 10) + str[d] - 48;
		d++;
	}
	return (res * s);
}

int	ft_isdigit(int c)
{
	if ((c <= 57) && (c >= 48))
		return (1);
	return (0);
}

int	ft_isalpha(int i)
{
	if (((i <= 122) && (i >= 97)) || ((i <= 90) && (i >= 65)))
		return (1);
	return (0);
}

int	len_read(char **tab, int i)
{
	int	len;

	len = 0;
	while (tab[i][len])
		len++;
	return (len);
}
