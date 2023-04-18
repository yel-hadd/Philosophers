NAME = philo
HEADER = philo.h
SRC := main.c

OBJ        := $(SRC:.c=.o)

%.o : %.c ${HEADER}
	@cc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) 
	@cc $(OBJ) -Wall -Werror -Wextra -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re