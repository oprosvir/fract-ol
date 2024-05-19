NAME	= fractol

SRCDIR	= src
INCDIR	= include

SRC		= 	main.c color.c event_handler.c mandelbrot.c render.c julia.c \
			utils.c error.c
SRCS	= $(addprefix $(SRCDIR)/, $(SRC))
OBJS	= $(SRCS:.c=.o)

LIBFT = libft/libft.a
LIBFT_PATH = libft/
LIBFT_INCLUDE = libft/include

MINILIBX = minilibx-linux/libmlx.a
MINILIBX_PATH = minilibx-linux/
MINILIBX_INCLUDE = minilibx-linux/

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm -o $(NAME)

# COLORS
GREEN = \033[1;38;5;76m
ROSEBUD = \033[1;38;5;199m
RESET = \033[0m

$(LIBFT):
	@echo "$(GREEN)Compiling libft..."
	@make -sC $(LIBFT_PATH)
	@echo "Libft compiled!$(RESET)"

$(MINILIBX):
	@echo "$(ROSEBUD)Сompiling MiniLibX...$(RESET)"
	@make -sC $(MINILIBX_PATH)
	@echo "$(ROSEBUD)MiniLibX compiled!$(RESET)"

src/%.o: src/%.c $(INCDIR)/fractol.h $(INCDIR)/defines.h
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFT_INCLUDE) -I$(MINILIBX_INCLUDE) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MINILIBX_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(MINILIBX)

re: fclean all


.PHONY: all clean fclean re