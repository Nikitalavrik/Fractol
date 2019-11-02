# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 15:00:08 by nlavrine          #+#    #+#              #
#    Updated: 2019/11/02 16:01:25 by nlavrine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	main.c					\
		fractol.c				\
		error.c					\
		catch_key.c				\
		choose_fractol.c		\
		vis.c					\
		thread.c				\
		fractals/bio.c			\
		fractals/buble_way.c	\
		fractals/burning_ship.c	\
		fractals/flower.c		\
		fractals/mandelbrot.c	\
		fractals/plane.c		\
		fractals/tunnel.c		\

CC = gcc
FLAGS = -Wall -Wextra -Werror 
SRC_DIR = srcs
H_DIR = includes
OBJ_DIR = obj
OBJ_DIR2 = obj/fractals
LIB = libft/libft.a
PRINTF = libft/ft_printf/libftprintf.a
MINILIBX = minilibx_macos/libmlx.a
GREEN = \033[0;32m

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME) 

$(NAME): $(LIB) $(PRINTF) $(OBJS)
		@echo "$(GREEN)Compile $(NAME)"
		@$(CC) $(FLAGS) -framework OpenGL -framework AppKit -lm  -lpthread $(OBJS) $(PRINTF) $(LIB) $(PRINTF) $(MINILIBX) -o $(NAME)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@mkdir -p $(OBJ_DIR2)
		@$(CC) $(FLAGS) -o $@ -c $< -I $(H_DIR) 

$(LIB):
	@echo "$(GREEN)Compile libft"
	@make -C ./libft/

$(PRINTF):
	@echo "$(GREEN)Compile ft_printf"
	@make -C ./libft/ft_printf/

clean:
	@echo "$(GREEN)Clear objs"
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR2)
	@make -C ./libft/ clean
	@make -C ./libft/ft_printf/ clean

fclean: clean
	@echo "$(GREEN)Clear $(NAME)"
	@rm -f $(NAME)
	@make -C ./libft/ fclean
	@make -C ./libft/ft_printf/ fclean

re: fclean all