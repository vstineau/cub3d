NAME 			= cub3d
CC 				= cc #clang
CFLAGS 		= -Wall -Wextra -Werror -MMD -g3 -O2 -fno-builtin
SRC_PATH 	= src/
OBJ_PATH 	= .obj/
SRC_NAME 	=	main.c \
				exec/image.c \
				exec/mouse.c \
				exec/game_loop.c \
				exec/player_motions.c \
				exec/player_motions2.c \
				exec/raycasting.c \
				exec/raycasting_utils.c \
				exec/textures.c \
				exec/window_action.c \
				parsing/check_colors.c \
				parsing/check_errors_utils.c \
				parsing/check_errors.c \
				parsing/check_map_utils.c \
				parsing/check_map.c \
				parsing/get_map_info.c \
				parsing/get_map_utils.c \
				parsing/get_map.c \
				parsing/map_manage.c \
				parsing/parsing.c
OBJ_NAME 	= $(SRC_NAME:.c=.o) 
MINILIBX	= .minilibx-linux/libmlx.a
LIBFT 		= .LIBFT/libft.a
INCLUDES 	= -I. -ILIBFT -IMINILIBX)
OBJ 			= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC 			= $(addprefix $(SRC_PATH), $(SRC_NAME))

.DEFAULT_GOAL := all

display_ascii_art :
	@echo "$(BHI_YELLOW)                  ,   __, ,                          $(RESET)"
	@echo "$(BHI_YELLOW)  _.._         )\\/(,-' (-' \`.__                      $(RESET)"
	@echo "$(BHI_YELLOW)  /_   \`-.      )'_      \` _  (_    _.---._          $(RESET)"
	@echo "$(BHI_YELLOW) // \\     \`-. ,'   \`-.    _\\\`.  \`.,'   ,--.\\         $(RESET)"
	@echo "$(BHI_YELLOW)// -.\\       \`        \`.  \\\`.   \`/   ,'   ||         $(RESET)"
	@echo "$(BHI_YELLOW)|| _ \`\\_         ___    )  )     \\  /,-'  ||         $(RESET)"
	@echo "$(BHI_YELLOW)||  \`---\\      ,'__ \\   \`,' ,--.  \\/---. //          $(RESET)"
	@echo "$(BHI_YELLOW) \\\\\\\\  .---\`.   / /  | |      |,-.\\ |\`-._ //           $(RESET)"
	@echo "$(BHI_YELLOW)  \`..___.'|   \\ |,-| |      |_  )||\\___//            $(RESET)"
	@echo "$(BHI_YELLOW)    \`.____/    \\\\\\\\\\\\O| |      \\o)// |____/             $(RESET)"
	@echo "$(BHI_YELLOW)         /      \`---/        \\-'  \\                  $(RESET)"
	@echo "$(BHI_YELLOW)         |        ,'|,--._.--')    \\                 $(RESET)"
	@echo "$(BHI_YELLOW)         \\       /   \`n     n'\\    /                 $(RESET)"
	@echo "$(BHI_YELLOW)          \`.   \`<   .::\`-,-\'::.),'                  $(RESET)"
	@echo "$(BHI_YELLOW)           \`.   \\-.____,^.   /,'                     $(RESET)"
	@echo "$(BHI_YELLOW)              \`. ;\`.,-V-.-.\`v'                       $(RESET)"
	@echo "$(BHI_YELLOW)                \\| \\     \` \\|\\                       $(RESET)"
	@echo "$(BHI_YELLOW)                 ;  \`-^---^-'/                       $(RESET)"
	@echo "$(BHI_YELLOW)                  \`-.______,'                        $(RESET)"

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

B_BLACK			= \033[1;30m
B_RED 			= \033[1;31m
B_GREEN			= \033[1;32m
B_YELLOW		= \033[1;33m\002
B_BLUE			= \033[1;34m
B_MAGENTA		= 033[1;35m
B_CYAN			= \033[1;36m
B_WHITE			= \033[1;37m

BHI_BLACK		= \033[1;90m
BHI_RED			= \033[1;91m
BHI_GREEN		= \033[1;92m
BHI_YELLOW	= \033[1;93m
BHI_BLUE		= \033[1;94m
BHI_MAGENTA	= \033[1;95m
BHI_CYAN		= \033[1;96m
BHI_WHITE		= \033[1;97m

BG_BLACK		= \033[40m
BG_RED			= \033[41m
BG_GREEN		= \033[42m
BG_YELLOW		= \033[43m
BG_BLUE			= \033[44m
BG_MAGENTA	= \033[45m
BG_CYAN			= \033[46m
BG_WHITE		= \033[47m

BGHI_BLACK		= \033[0;100m
BGHI_RED			= \033[0;101m
BGHI_GREEN		= \033[0;102m
BGHI_YELLOW		= \033[0;103m
BGHI_BLUE			= \033[0;104m
BGHI_MAGENTA	= \033[0;105m
BGHI_CYAN			= \033[0;106m
BGHI_WHITE		= \033[0;107m

RESET				= \033[0m

