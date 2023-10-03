NAME = pipex
CC = gcc
BONUS = pipex_bonus
CFLAGS = -Wall -Werror -Wextra -g0 #-fsanitize=address
SRC_FILES = pipex.c \
			ft_split.c \
			ft_error.c \
			ft_exec.c

INCLUDE = pipex.h

OBJS = $(SRC_FILES:.c=.o)

all: lib $(NAME)

bonus:
	make -C bonus_pipex
	cp bonus_pipex/$(BONUS) $(BONUS)

%.o: %.c
	$(CC) -c $(CFLAGS)  $^

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C bonus_pipex clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)
	make -C bonus_pipex fclean

re: fclean all

.PHONY: all clean fclean re lib