# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haristot <haristot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/21 16:20:18 by haristot          #+#    #+#              #
#    Updated: 2021/02/27 20:51:57 by haristot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =  utils/parser.c \
		utils/res_tex.c \
		utils/color.c \
		utils/scan_map.c \
		utils/check_map.c \
		utils/check_map2.c \
		utils/ser_sprites.c \
		raycast/key_hook.c \
		raycast/screen.c \
		raycast/utils.c \
		raycast/sort_sprites.c \
		raycast/sprite.c \
		raycast/raycasting.c \
		raycast/rayc_calc.c \
		raycast/cub3d.c \
		raycast/utils_sec.c \
		
MLX = -lmlx -framework OpenGL -framework AppKit

OBJSRCS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJSRCS) 
	@echo "\033[0;36m[Deleting the previous cube...]"
	@rm -rf cub3D
	@echo "\033[0;36m[Libft compilation...]"
	@$(MAKE) -C ./libft
	@echo "\033[0;36m[mlx compilation...]"
	@$(MAKE) -C ./mlx
	@echo "\033[0;36m[Cub3D compilation...]"
	gcc $(OBJSRCS) -I./include ./libft/libft.a libmlx.dylib -I./mlx $(MLX) -o $(NAME)
	@echo "\033[0;36m[Done !]"

test:
		gcc libft/libft.a utils/*.c raycast/*.c  -Iinclude -Imlx -Lmlx -lmlx  -framework Appkit -framework OpenGL -o $(NAME) \
		-Wall -Wextra

clean :
	rm -rf $(OBJSRCS) 
	$(MAKE) clean -C ./libft

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	rm -rf cub3d.bmp

re : fclean all

bonus : $(NAME)

.PHONY: clean fclean re all