NAME = push_swap.exe
CC = cc
HEADERS_DIR = /includes
PUSH_SWAP_SRC_DIR = ./src/push_swap
PUSH_SWAP_SRC = push_swap.c parse_data.c parse_data_utils_1.c parse_data_utils_2.c ft_atol.c ft_stacknew.c free.c ft_stackdelone.c ft_stacklast.c ft_stacksize.c ft_stack_add_back.c ft_stack_add_top.c ft_utils.c ft_check.c ft_sort.c ft_operations_1.c ft_operations_2.c ft_stack_utils.c ft_sort_a_to_b.c ft_utils_2.c ft_puterror.c ft_sort_b_to_a.c ft_final_rot.c
CFILES = $(addprefix $(PUSH_SWAP_SRC_DIR)/, $(PUSH_SWAP_SRC))
CFLAGS = -Wall -Werror -Wextra -I $(HEADERS_DIR)
CFLAGS_LEAKS = -Wall -Werror -Wextra -g -I $(HEADERS_DIR)
OBJFILES = $(CFILES:.c=.o)
MAKEFLAGS += --no-print-directory

libft_dir = libft
libft = $(libft_dir)/libft.a

ft_printf_dir = ft_printf
ft_printf = $(ft_printf_dir)/libftprintf.a

gnl_dir = gnl
gnl = $(gnl_dir)/gnl.a

# Bonus
CHECKER = checker.exe
CHECKER_SRC_DIR = ./src/checker
# Functions of main push_swap to reuse for checker
MAIN_SRCES = parse_data.c free.c ft_stackdelone.c parse_data_utils_1.c parse_data_utils_2.c ft_puterror.c ft_atol.c ft_stacknew.c ft_stack_add_back.c ft_stack_add_top.c ft_stacklast.c ft_stacksize.c ft_utils.c ft_check.c
CHECKER_SRC = checker.c ft_ch_operations_1.c ft_ch_operations_2.c
CHECKER_CFILES = $(addprefix $(CHECKER_SRC_DIR)/, $(CHECKER_SRC)) $(addprefix $(PUSH_SWAP_SRC_DIR)/, $(MAIN_SRCES))
CHECKER_OBJFILES = $(CHECKER_CFILES:.c=.o)

# Colors
GREEN = \033[0;32m
RED = \033[1;31m
BLUE_UNDER = \033[1;34m
YELLOW = \033[0;33m
CYAN = \033[1;36m
MAGENTA = \033[0;35m
WHITE = \033[1;37m
WHITE_RED_BG = \033[0;41;37m
YELLOW_UNDER = \033[1;4;33m
NC = \033[0m

all: $(libft) $(ft_printf) $(NAME)

$(NAME): $(OBJFILES) $(libft)
	@echo "$(BLUE_UNDER)Compiling $(NAME)$(NC)"
	@$(CC) $(CFLAGS) $(OBJFILES) $(libft) $(ft_printf) -o $(NAME)

$(libft):
	@$(MAKE) -C $(libft_dir) all

$(ft_printf):
	@$(MAKE) -C $(ft_printf_dir) all

clean:
	@echo "$(BLUE_UNDER)Removing .o files in all directories$(NC)"
	@$(MAKE) -C $(libft_dir) clean
	@$(MAKE) -C $(ft_printf_dir) clean
	@$(MAKE) -C $(gnl_dir) clean
	@rm -rf .b $(CHECKER_OBJFILES)
	@rm -rf .b $(OBJFILES)

fclean: clean
	@echo "$(BLUE_UNDER)Removing .a files and executables$(NC)"
	@$(MAKE) -C $(libft_dir) fclean
	@$(MAKE) -C $(ft_printf_dir) fclean
	@$(MAKE) -C $(gnl_dir) fclean
	@rm -rf $(NAME)
	@rm -rf $(CHECKER)

re: fclean all

clean_all: clean fclean

# Bonus
bonus: $(libft) $(ft_printf) $(gnl) $(CHECKER)

$(CHECKER): $(CHECKER_OBJFILES) $(libft) $(ft_printf)
	@echo "$(BLUE_UNDER)Compiling $(CHECKER)$(NC)"
	@$(CC) $(CFLAGS) $(CHECKER_OBJFILES) $(libft) $(ft_printf) $(gnl) -o $(CHECKER)

$(gnl):
	@$(MAKE) -C $(gnl_dir) all

# Testing commands
exe: all
	@echo "$(BLUE_UNDER)Executing $(NAME)...$(NC)"
	@./$(NAME) "$(ARGS)"
	@echo "$(GREEN)Program executed"
	@echo "$(BLUE_UNDER)Removing $(NAME)...$(NC)"
	@rm -rf $(NAME)

all_leaks: $(libft) $(ft_printf) $(NAME)

$(NAME): $(OBJFILES) $(libft)
	@echo "$(BLUE_UNDER)Compiling $(NAME)$(NC)"
	@$(CC) $(CFLAGS_LEAKS) $(OBJFILES) $(libft) $(ft_printf) -o $(NAME)

leaks: all_leaks clean
	@echo "$(BLUE_UNDER)Checking $(NAME) with valgrind...$(NC)"
	@valgrind --leak-check=full --show-leak-kinds=all  ./$(NAME) "58 32 16"
	@echo "$(BLUE_UNDER)Removing $(NAME)...$(NC)"
	@rm -rf $(NAME)
	@$(MAKE) fclean

# Use just for development to pass args to checker
exe_bonus: bonus
	@echo "$(BLUE_UNDER)Executing $(CHECKER)...$(NC)"
	@./$(CHECKER) "$(ARGS)"
	@echo "$(GREEN)Program executed"
	@echo "$(BLUE_UNDER)Removing $(CHECKER)...$(NC)"
	@rm -rf $(CHECKER)

.PHONY: all clean fclean re clean_all exe all_leaks leaks bonus exe_bonus

