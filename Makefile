NAME =  fdf
FLAGS = -Wall -Werror -Wextra
FDF_FILES = $(addprefix src/fdf_files/, main.c bresenham_line_algorithm.c map.c validation_map.c give_intarr.c draw_map.c ft_interface.c key_hook.c rotate_coor.c draw_axis.c move_map.c change_color.c print_legend.c)
INCLUDES = -I ./includes
MLX_H = -I /usr/local/include
MLX_LIB = -L /usr/local/lib
LIBFTPRINTF_LIB = ./src/libftprintf/libftprintf.a
LINKING = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(FDF_FILES)
	@make all -C ./src/libftprintf
	@gcc $(FLAGS) $(MLX_H) $(INCLUDES) -o $(NAME) $(FDF_FILES) $(LIBFTPRINTF_LIB) $(MLX_LIB) $(LINKING)
	@echo "\033[0;32mFDF compiled.\033[0m "

clean:
	@make clean -C ./src/libftprintf
	@echo "\033[0;32mCLEANED FDF\033[0m "

fclean: clean
	@make fclean -C ./src/libftprintf
	@rm -f $(NAME)

re:
	@make fclean
	@make
