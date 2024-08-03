NAME = philo

SRC = main.c \
		utils.c \
		parsing.c \
		handle_thread.c \
		ft_routine.c \
		handle_death.c \

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror

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
