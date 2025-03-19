SRCS =	src/parssing.c\
		src/ft_clean.c\
		src/utils.c
	
OBJS = $(SRCS:.c=.o)


CC = cc
CFLAGS = -Wextra -Werror -Wall
INCLUDES = -I./includes -I./src

LIBS =	-L../includes/libft\
		-lft

NAME = push_swap

all: libft $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

libft:
	@make -C includes/libft bonus > /dev/null 2>&1
	@echo "[....Libft....] Successfully compiled."

clean:
	@make -C includes/libft clean > /dev/null 2>&1
	@echo "[....Libft....] Cleaned."

fclean: clean
	@make -C includes/libft fclean > /dev/null 2>&1
	@echo "[....Libft....] Cleaned."
	@rm -f $(OBJS) $(NAME)
	@echo "[...Objects...] Cleaned."
re: fclean all 

.PHONY: all clean fclean re libft