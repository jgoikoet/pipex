NAME = gnl.a
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC_FILES = get_next_line.c \
			get_next_line_utils.c

HEADER = get_next_line.h
LIBC = ar rcs

OBJS = $(SRC_FILES:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAG) $^

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re