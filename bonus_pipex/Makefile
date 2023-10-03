NAME = pipex_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address
GNL = gnl.a
SRC_FILES = pipex.c \
			ft_split.c \
			ft_error.c \
			ft_exec.c \
			ft_exec_here_doc.c

INCLUDE = pipex.h

OBJS = $(SRC_FILES:.c=.o)

all: lib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS)  $^

lib:
	make -C gnl
	cp gnl/$(GNL) $(GNL)

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) $(GNL) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C gnl clean

fclean: clean
	rm -f $(NAME)
	rm -f $(GNL)
	make -C gnl fclean

re: fclean all

.PHONY: all clean fclean re lib