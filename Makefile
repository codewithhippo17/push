SRCS =	push_swap.c\
		src/parsing.c\
		src/ft_clean.c\
		src/ft_check.c\
		src/ft_op_r.c\
		src/ft_op_sp.c\
		src/sort_helpers.c\
		src/utils.c

SRC_BNS =	checker.c\
			src/parsing.c\
			src/ft_clean.c\
			src/ft_check.c\
			src/ft_op_r.c\
			src/ft_op_sp.c\
			src/sort_helpers.c\
			src/utils.c
		  
	
OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(SRC_BNS:.c=.o)

CC = cc
CFLAGS = -Wextra -Werror -Wall -g
INCLUDES = -I./includes

LIBS =	-L./includes/libft\
		-lft

LIBS_BNS =	-L./includes/libft\
			-L./includes/gnl\
			-lft -lgnl

NAME = push_swap
NAME_BONUS = checker

all: libft $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo "\033[1;92m[..push_swap..] Successfully compiled.\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ $(INCLUDES) -o $@
	@echo "[.$^.] Bulding object files..."

bonus: libft gnl $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BNS)
	@$(CC) $(OBJS_BNS) $(INCLUDES) $(LIBS_BNS) -o $(NAME_BONUS)
	@echo "\033[1;92m[..checker..] Successfully compiled.\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ $(INCLUDES) -o $@
	@echo "[.$^.] Bulding object files..."

gnl:
	@$(MAKE) -C includes/gnl 2>&1 | grep -q "Nothing to be done for 'all'" && \
	echo "[.....gnl.....] Nothing to be done for 'all'." || \
	echo "[.....gnl.....] Successfully compiled."

libft:
	@$(MAKE) -C includes/libft 2>&1 | grep -q "Nothing to be done for 'all'" && \
	echo "[....Libft....] Nothing to be done for 'all'." || \
	echo "[....Libft....] Successfully compiled."

clean:
	@$(MAKE) -C includes/libft clean > /dev/null 2>&1
	@echo "[....Libft....] Cleaned."
	@$(MAKE) -C includes/gnl clean > /dev/null 2>&1
	@echo "[.....gnl.....] Cleaned."
	@rm -f $(OBJS) $(OBJS_BNS)
	@echo "[...Objects...] Cleaned."

fclean:
	@$(MAKE) -C includes/libft fclean > /dev/null 2>&1
	@echo "[....Libft....] Cleaned."
	@$(MAKE) -C includes/gnl fclean > /dev/null 2>&1
	@echo "[.....gnl.....] Cleaned."
	@rm -f $(OBJS) $(OBJS_BNS)
	@echo "[...Objects...] Cleaned."
	@if rm $(NAME) 2>/dev/null; then \
		echo "\033[1;91m[..push_swap..] push_swap shuted down.\033[0m"; \
	fi
	@if rm $(NAME_BONUS) 2>/dev/null; then \
		echo "\033[1;91m[..checker....] checker shuted down.\033[0m"; \
	fi

re: fclean all

# gdb: CFLAGS += -g
# gdb: re
# 	@gdb -tui --args push_swap map.fdf

.PHONY:  clean fclean re libft
.SECONDARY : $(OBJS) $(OBJS_BNS) 