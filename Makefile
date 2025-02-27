.PHONY: clean fclean re
.SUFFIXES:

CC =		gcc
EXEC =		wolf3d
LIB =		ft
SRCS_DIR =	./src/
OBJS_DIR =	./
LIB_DIR = 	./libft/
#MLX = 		-I/usr/local/include/ -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
MLX = 		-I/usr/local/include/ -L/usr/local/lib -lmlx_Linux -L/usr/X11/lib -lXext -lX11
HEADER =	./include/
CFLAGS =	-Wall -Werror -Wextra -g
ARFLAGS =	-rcs
CFILES =	main get_next_line raycast event init parsing

SRCS =		$(CFILES:%=$(SRCS_DIR)%.c)
OBJS =		$(SRCS:%.c=$(OBJS_DIR)%.o)

all:
	make -C libft/
	$(CC) $(SRCS) -I$(HEADER) -Ilibft/ -L$(LIB_DIR) -l$(LIB) $(MLX) -o $(EXEC) $(CFLAGS)

clean:
	rm -f $(OBJS)
	@make -C libft/ clean
	@echo clean $@ Done !

fclean:		clean
	rm -f $(EXEC)
	@make -C libft/ fclean
	@echo fclean $@ Done !

re:			fclean all

##-Lminilibx_macos
