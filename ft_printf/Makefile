NAME = libftprintf.a
COMP_NAME = printf.exe
CC = cc
AR = ar
AR_FLAGS = -rcs
CFILES = ft_printf.c ft_putchar_fd_custom.c ft_putstr_fd_custom.c ft_putnbr_fd_custom.c ft_puthexa.c ft_strlen.c ft_put_unsign.c ft_putptr.c
MAIN = ../main.c
HEADERS_DIR = /
OBJS = $(CFILES:.c=.o)
CFLAGS = -Wall -Werror -Wextra -I $(HEADERS_DIR)

all: $(NAME)

$(NAME):$(OBJS)
	@$(AR) $(AR_FLAGS) $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

# Testing commands

compile: $(CFILES) $(MAIN)
	@echo "Compiling $(COMP_NAME) …"
	@$(CC) $(CFLAGS) $(CFILES) $(MAIN) -o ../$(COMP_NAME)

exe: compile
	@echo "Executing $(COMP_NAME) …"
	@../$(COMP_NAME)
	@echo "Removing $(COMP_NAME)…"
	@rm -rf ../$(COMP_NAME)

.PHONY: all clean fclean re compile exe
