NAME = philo
HEADER = philo.h
SRC = main.c \
	check_params.c \
	ft_isdigit.c \
	ft_strncmp.c \
	parse_philos.c \
	fork_add_back.c \
	ft_memcpy.c \
	new_fork.c \
	philo_add_back.c \
	ft_atoi.c \
	ft_memset.c \
	new_philo.c \
	routine.c \
	ft_bzero.c \
	ft_strdup.c \
	parse_forks.c \
	ft_calloc.c \
	ft_strlen.c \
	parse_params.c

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