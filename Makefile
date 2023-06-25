NAME = philo

SRCS = main.c \
	utils/check_params.c \
	utils/ft_memcpy.c \
	utils/new_fork.c \
	utils/fork_add_back.c \
	utils/ft_memset.c \
	utils/new_philo.c \
	utils/ft_strdup.c \
	utils/parse_forks.c \
	utils/ft_strlen.c \
	utils/parse_params.c \
	utils/ft_atoi.c \
	utils/ft_strncmp.c \
	utils/parse_philos.c \
	utils/ft_bzero.c \
	utils/ft_usleep.c \
	utils/philo_add_back.c \
	utils/ft_calloc.c \
	utils/get_ms_ts.c \
	utils/routine.c \
	utils/ft_isdigit.c \
	utils/start_threads.c \
	utils/is_all_digits.c \
	utils/check_death.c \
	utils/free_all.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lpthread

HEADER = philo.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
