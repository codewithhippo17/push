SRCS =	push_swap.c\
		src/parsing.c\
		src/ft_clean.c\
		src/ft_check.c\
		src/ft_op_r.c\
		src/ft_op_sp.c\
		src/utils.c
	
OBJS = $(SRCS:.c=.o)


CC = cc
CFLAGS = -Wextra -Werror -Wall -g
INCLUDES = -I./includes

LIBS =	-L./includes/libft\
		-lft

NAME = push_swap

all: libft $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo "\e[32m[..push_swap..] Successfully compiled.\e[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ $(INCLUDES) -o $@
	@echo "[.$^.] Bulding object files..."

libft:
	@make -C includes/libft > /dev/null 2>&1
	@make -C includes/libft bonus > /dev/null 2>&1
	@echo "[....Libft....] Successfully compiled."

clean:
	@make -C includes/libft clean > /dev/null 2>&1
	@echo "[....Libft....] Cleaned."
	@rm -f $(OBJS)
	@echo "[...Objects...] Cleaned."

fclean:
	@make -C includes/libft fclean > /dev/null 2>&1
	@echo "[....Libft....] Cleaned."
	@rm -f $(OBJS)
	@echo "[...Objects...] Cleaned."
	@rm -f $(NAME)
	@echo  "\e[33m[..push_swap..] Fdf shuted down.\e[0m\n"

re: fclean all

gdb: CFLAGS += -g
gdb: re
	@gdb -tui --args push_swap map.fdf

.PHONY: all clean fclean re libft