NAME			= fractol

OBJDIR			= obj/
INCDIR			= include/
SRCDIR			= src/

SRCS			= 	src/main.c \
					src/parse.c \
					src/render.c\
					src/events_mouse.c \
					src/events_keyboard.c \
					src/color.c \
					src/utils.c \
					src/error.c \
					src/exit.c

OBJS			= $(SRCS:src/%.c=$(OBJDIR)%.o)

LIBFT_DIR		= libft/
LIBFT			= libft/libft.a

MINILIBX_DIR	= minilibx-linux/
MINILIBX		= minilibx-linux/libmlx.a

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
LDFLAGS			= -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES		= -I$(INCDIR) -I$(LIBFT_DIR)include -I$(MINILIBX_DIR)
RM				= rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCDIR)fractol.h $(INCDIR)defines.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# COLORS
GREEN = \033[1;38;5;76m
ROSEBUD = \033[1;38;5;199m
RESET = \033[0m

$(LIBFT):
	@echo "$(GREEN)Compiling libft..."
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "Libft compiled!$(RESET)"

$(MINILIBX):
	@echo "$(ROSEBUD)Compiling MiniLibX...$(RESET)"
	@$(MAKE) -sC $(MINILIBX_DIR)
	@echo "$(ROSEBUD)MiniLibX compiled!$(RESET)"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(MINILIBX)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus