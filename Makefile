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
			-lft -lgnl

NAME = push_swap
NAME_BONUS = checker

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)
# echo "\e[32m[..checker..] Successfully compiled.\e[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ $(INCLUDES) -o $@
	@echo "[.$^.] Bulding object files..."

bonus: libft gnl $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BNS)
	@$(CC) $(OBJS_BNS) $(INCLUDES) $(LIBS) -o $(NAME_BONUS)
	@echo "\e[32m[..push_swap..] Successfully compiled.\e[0m"

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
	@echo "\e\033[31m   ~~~~~~~~~~~~\e[0m"

fclean:
	@$(MAKE) -C includes/libft fclean > /dev/null 2>&1
	@echo "[....Libft....] Cleaned."
	@$(MAKE) -C includes/gnl fclean > /dev/null 2>&1
	@echo "[.....gnl.....] Cleaned."
	@rm -f $(OBJS) $(OBJS_BNS)
	@echo "[...Objects...] Cleaned."
	@rm -f $(NAME) $(NAME_BONUS)
	@echo  "\e\033[31m[..push_swap..] Fdf shuted down.\e[0m"
	@echo "\e\033[31m    ~~~~~~~~~~~~\e[0m"

re: fclean all

# gdb: CFLAGS += -g
# gdb: re
# 	@gdb -tui --args push_swap map.fdf

.PHONY:  clean fclean re libft
.SECONDARY : $(OBJS) $(OBJS_BNS) 