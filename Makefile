NAME	= fractol

SRCDIR	= src
INCDIR	= include

SRC		= main.c
SRCS	= $(addprefix $(SRCDIR)/, $(SRC))
OBJS	= $(SRCS:.c=.o)

LIBFT = libft/libft.a
LIBFT_PATH = libft/
LIBFT_INCLUDE = libft/include

MINILIBX = minilibx-linux/libmlx.a
MINILIBX_PATH = minilibx-linux/
MINILIBX_INCLUDE = minilibx/

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm -o $(NAME)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(MINILIBX):
	@echo "Making MiniLibX..."
	@make -sC $(MINILIBX_PATH)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFT_INCLUDE) -I$(MINILIBX_INCLUDE) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MINILIBX_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(MINILIBX)

re: fclean all


.PHONY: all clean fclean re