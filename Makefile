NAME = philo
HEADER = philo.h
SRC := main.c \
	utils/check_params.c \
	utils/ft_memcpy.c \
	utils/new_philo.c \
	utils/fork_add_back.c \
	utils/ft_memset.c \
	utils/parse_forks.c \
	utils/ft_atoi.c \
	utils/ft_strdup.c \
	utils/parse_params.c \
	utils/ft_bzero.c \
	utils/ft_strlen.c \
	utils/ft_calloc.c \
	utils/ft_strncmp.c \
	utils/philo_add_back.c \
	utils/ft_isdigit.c \
	utils/new_fork.c \
	utils/parse_philos.c

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