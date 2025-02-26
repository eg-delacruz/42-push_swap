NAME = gnl.a
CC = cc
AR = ar
AR_FLAGS = -rcs
CFILES = get_next_line.c get_next_line_utils.c
OBJS = $(CFILES:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):$(OBJS)
	@$(AR) $(AR_FLAGS) $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re