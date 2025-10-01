# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 14:57:58 by thblack-          #+#    #+#              #
#    Updated: 2025/10/01 11:37:52 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT NAME
PROJECT		= fract-ol
NAME		= fract-ol

# PROJECT DIRECTORIES
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc

# PROJECT SOURCES: Explicitly states
SRC_FILES	= main.c color.c navigation.c julia.c mandelbrot.c maths.c \
				ft_atof.c messages.c
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# PROJECT HEADER
HEADER		= $(INC_DIR)/fract_ol.h

# PROJECT OBJECTS
OBJ		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# TOOLS
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
MAKE_QUIET	= --no-print-directory
SHELL_QUIET	= $(if $(DEBUG),,> /dev/null)
MAKE_LIB	= make -C
CMAKE_LIB	= cmake

# REMOVE
RM		= rm -rf

# MAKE DIRECTORY
MKDIR		= mkdir -p

# LIBFT LINKING
LIBFT_DIR	= ./libft
LIBFT_H		= $(LIBFT_DIR)/libft.h
LIBFT_A		= $(LIBFT_DIR)/libft.a

# MLX42 LINKING
MLX42_DIR	= ./MLX42
MLX42_H		= $(MLX42_DIR)/include/MLX42/MLX42.h
MLX42_A		= $(MLX42_DIR)/build/libmlx42.a

# INCLUDE PATHS AND LIBRARIES
INC			= -I. -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX42_DIR)/include
LIBFT		= -L$(LIBFT_DIR) -lft
MLX42		= -L$(MLX42_DIR)/build -lmlx42
GLFW_42		= -lglfw
GLFW_MAC	= $(shell pkg-config --cflags --libs glfw3) -framework Cocoa -framework OpenGL -framework IOKit
LIBS		= $(LIBFT) $(MLX42) $(GLFW_42)

# <<<<<<< MAIN TARGETS >>>>>>>

all: start $(NAME) finish

$(NAME): $(OBJ) $(LIBFT_A) $(MLX42_A)
	@echo "==== BUILDING $(PROJECT) ======"
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "$(PROJECT) compiled"

$(MLX42_A):
	@echo "==== BUILDING MLX42_FT ======"
	@$(CMAKE_LIB) -S $(MLX42_DIR) -B $(MLX42_DIR)/build $(SHELL_QUIET)
	@$(CMAKE_LIB) --build $(MLX42_DIR)/build -j4 $(SHELL_QUIET)
	@echo "MLX42 compiled"

$(LIBFT_A):
	@$(MAKE_LIB) $(LIBFT_DIR) $(MAKE_QUIET)

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) $(LIBFT_H) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# <<<<<<< PHONY TARGETS >>>>>>>

start:
	@echo "==== THOMASROFF MAKEFILE ===="

finish:
	@echo "==== BUILD COMPLETE ========="

clean:
	@echo "Removing object files"
	@$(RM) $(OBJ)
	@$(MAKE_LIB) libft clean $(MAKE_QUIET)
	@$(CMAKE_LIB) --build $(MLX42_DIR)/build --target clean $(SHELL_QUIET)

fclean: clean
	@echo "Removing static library files"
	@$(RM) $(NAME)
	@$(MAKE_LIB) libft fclean $(MAKE_QUIET)
	@$(RM) $(MLX42_DIR)/build

re: fclean all

.PHONY: all start finish clean fclean re
