/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:54:24 by bbousaad          #+#    #+#             */
/*   Updated: 2024/08/04 17:54:26 by bbousaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <termios.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <pthread.h>

typedef struct s_philo t_philo;
typedef struct s_data t_data;

// chaque philo
typedef struct s_philo { 
	int             id;
	int             nb_philo;
	int             t_die;
	int             t_eat;
	int             t_sleep;
	int             t_must_eat;
	int             t_have_eat;
	int             finish_eat;
	struct timeval  time;
	struct timeval  last_eat;
	struct timeval	eat;				
	pthread_mutex_t *forks;
	int             left_fork;
	int             right_fork;
}  t_philo;

// principale
typedef struct s_data { 
	int             t_die;
	int             t_eat;
	int             t_sleep;
	int             t_must_eat;
	int             t_have_eat;
	int             finish_eat;
	int             error;
	int             nb_philo;
	t_philo         *philos;
}   t_data;

//UTILS
int     ft_atoi(char *str);
int     ft_isdigit(int c);
int	    ft_isalpha(int i);
int	    len_read(char **tab, int i);
//INITIALISATION
void	initialize(t_data *dta, char **argv);
void    init_philo(t_data *dta, int i);
//PARSING
void	parse_args(t_data *dta, int argc, char **argv);
void	parse_args2(t_data *dta, int argc, char **argv);
void	parse_args3(t_data *dta, int argc, char **argv);
//HANDLE_PTHREAD
void	handle_thread(t_data *dta);
void    handl_thread2(t_data *dta);
void    *ft_routine(void *dta);
//ROUTINE
void    ft_eating(t_philo *philo);
void    ft_sleeping(t_philo *philo);
void    ft_thinking(t_philo *philo);
void    ft_died(t_philo *philo);
//CHECKER_OF_DEATH
void    *handle_death(void *philos);

#endif
