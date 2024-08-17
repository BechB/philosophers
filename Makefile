# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbousaad <bbousaad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 19:45:06 by bbousaad          #+#    #+#              #
#    Updated: 2024/08/17 20:05:45 by bbousaad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c \
		utils.c \
		parsing.c \
		handle_thread.c \
		ft_routine.c \
		handle_death.c \
		free_destroy.c \
		one_philo.c \

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror #-fsanitize=thread -g

.c.o = $(CC) -c -o $(OBJ)

$(NAME): $(OBJ)
	@${CC} $(OBJ) -o $(NAME)
	@echo "Archivage terminé [philo]"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "Suppression des .o"

fclean: clean
	@rm -f $(OBJ) $(NAME)
	@echo "Suppression du .a effectuée"

re: fclean all

.PHONY : all clean fclean re
