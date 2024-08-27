NAME 			= cub3d
CC 				= cc #clang
CFLAGS 		= -Wall -Wextra -Werror -MMD -g3 -fno-builtin
SRC_PATH 	= src/
OBJ_PATH 	= .obj/
SRC_NAME 	= main.c \
						exec/image.c \
						exec/player_motions.c \
						exec/player_motions2.c \
						exec/parsing_liddle.c \
						exec/raycasting.c \
						exec/sprite.c \
						exec/window_action.c 
OBJ_NAME 	= $(SRC_NAME:.c=.o) 
MINILIBX	= .minilibx-linux/libmlx.a
LIBFT 		= .LIBFT/libft.a
INCLUDES 	= -I. -ILIBFT -IMINILIBX)
OBJ 			= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC 			= $(addprefix $(SRC_PATH), $(SRC_NAME))

.DEFAULT_GOAL := all

display_ascii_art :
	@echo "\033[1;93m"
	@echo "                      (\`.-,') "
	@echo "                    .-'     ; "
	@echo "                _.-'   , \`,- "
	@echo "          _ _.-'     .'  /._ "
	@echo "        .' \`  _.-.  /  ,'._;) "
	@echo "       (       .  )-| ( "
	@echo "        )\`,_ ,'_,'  \_;) "
	@echo "('_  _,'.'  (___,)) "
	@echo " \`-:;.-' "
	@echo "\0033[00m"

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MINILIBX) -lm -lX11 -lXext -lft -L.LIBFT
	@$(MAKE) -s display_ascii_art

$(MINILIBX):
	@$(MAKE) -s -C .minilibx-linux

$(LIBFT):
	@$(MAKE) -s -C .LIBFT

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $<

-include $(OBJ:%.o=%.d)

clean:
	@$(MAKE) -s -C .LIBFT clean
	@$(MAKE) -s -C .minilibx-linux clean
	rm -rf .obj

fclean: clean
	@$(MAKE) -s -C .LIBFT fclean
	@$(MAKE) -s -C .minilibx-linux clean
	rm -rf $(NAME)

re:
	@$(MAKE) -s fclean all

.PHONY: all clean fclean re display_ascii_art
