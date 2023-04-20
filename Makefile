NAME = philo
HEADER = philo.h
SRC := main.c \
	utils/ft_bzero.c \
	utils/ft_calloc.c \
	utils/ft_memset.c \
	utils/ft_strdup.c \
	utils/ft_strlen.c \
	utils/ft_memcpy.c

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