# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 14:57:58 by thblack-          #+#    #+#              #
#    Updated: 2025/10/06 14:07:13 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT NAME
PROJECT		= fract-ol
NAME		= fractol

# PROJECT DIRECTORIES
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc

# PROJECT SOURCES: Explicitly states
SRC_FILES	= main.c color.c navigation.c julia.c mandelbrot.c maths.c \
				ft_atof.c messages.c init.c
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# PROJECT HEADER
HEADER		= $(INC_DIR)/fract_ol.h

# PROJECT OBJECTS
OBJ		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# TOOLS
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O3
MAKE_QUIET	= --no-print-directory
SHELL_QUIET	= $(if $(DEBUG),,> /dev/null 2>&1)
MAKE_LIB	= make -C
CMAKE_LIB	= cmake

# REMOVE
RMFILE = rm -f
RMDIR = rm -rf

# MAKE DIRECTORY
MKDIR		= mkdir -p

# LIBFT LINKING
LIBFT_DIR	= ./libft
LIBFT_H		= $(LIBFT_DIR)/libft.h
LIBFT_A		= $(LIBFT_DIR)/libft.a

# MLX42 LINKING
MLX42_DIR	= MLX42
MLX42_OBJ	= ./MLX42
MLX42_H		= $(MLX42_DIR)/include/MLX42/MLX42.h
MLX42_A		= $(MLX42_DIR)/build/libmlx42.a
MLX42_CLONE	= git clone https://github.com/codam-coding-college/MLX42.git

# INCLUDE PATHS AND LIBRARIES
INC			= -I. -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX42_DIR)/include
LIBFT		= -L$(LIBFT_DIR) -lft
MLX42		= -L$(MLX42_DIR)/build -lmlx42
GLFW_42		= -lglfw
GLFW_MAC	= $(shell pkg-config --cflags --libs glfw3) -framework Cocoa -framework OpenGL -framework IOKit
LIBS		= $(LIBFT) $(MLX42) $(GLFW_42)

# <<<<<<< MAIN TARGETS >>>>>>>

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(MLX42_A)
	@echo "==== THOMASROFF MAKEFILE ===="
	@echo "==== BUILDING $(PROJECT) ======"
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "$(PROJECT) compiled"
	@echo "==== BUILD COMPLETE ========="

$(MLX42_A):
	@if [ ! -d "$(MLX42_DIR)" ]; then \
		echo "==== CLONING MLX42 =========="; \
		$(MLX42_CLONE) $(SHELL_QUIET); \
		echo "MLX42 cloned"; \
	fi
	@echo "==== BUILDING MLX42_FT ======"
	@$(CMAKE_LIB) -S $(MLX42_OBJ) -B $(MLX42_OBJ)/build $(SHELL_QUIET)
	@$(CMAKE_LIB) --build $(MLX42_OBJ)/build -j4 $(SHELL_QUIET)
	@echo "MLX42 compiled"

$(LIBFT_A):
	@$(MAKE_LIB) $(LIBFT_DIR) $(MAKE_QUIET)

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

.SECONDARY: $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) $(LIBFT_A) $(MLX42_A) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# <<<<<<< PHONY TARGETS >>>>>>>

clean:
	@echo "Removing object files"
	@$(RMFILE) $(OBJ)
	@$(RMDIR) $(OBJ_DIR)
	@$(MAKE_LIB) libft clean $(MAKE_QUIET)
	@$(CMAKE_LIB) --build $(MLX42_OBJ)/build --target clean $(SHELL_QUIET)

fclean: clean
	@echo "Removing static library files"
	@$(RMFILE) $(NAME)
	@$(MAKE_LIB) libft fclean $(MAKE_QUIET)
	@$(RMDIR) $(MLX42_DIR)

re: fclean all

.PHONY: all clean fclean re
