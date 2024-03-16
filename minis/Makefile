NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lreadline -g -ggdb
RM = rm -rf
SRCS = 		arguman_init.c \
			env_init.c \
			env_print.c \
			export.c \
			ft_command.c \
			ft_error.c \
			ft_free.c \
			ft_signal.c \
			function_cd.c \
			function_echo.c \
			function_exit.c \
			function_pwd.c \
			function_slash.c \
			input_output.c \
			lexer_utils_three.c \
			lexer_utils_two.c \
			lexer_utils.c \
			lexer.c \
			main.c \
			parse.c \
			pipex_utils.c \
			pipex.c \
			unset.c \
			utils.c \
			variables.c \
			re_create.c

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
USER := $(shell whoami)
RL_INC = /usr/include

all: $(NAME)

$(NAME): $(SRCS) libft
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) #$(RL_FLAGS)

v:
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT) #$(RL_FLAGS)
	@valgrind ./$(NAME)

libft:
	@make -C $(LIBFT_PATH) all

clean:
	@make -C $(LIBFT_PATH) clean

fclean:
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft $(NAME) v
