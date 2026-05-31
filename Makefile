# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/31 14:50:19 by ynieto-s          #+#    #+#              #
#    Updated: 2026/05/31 16:18:14 by ynieto-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP

RM			= rm -rf

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

GNL_DIR		= gnl
GNL_SRC		= get_next_line.c get_next_line_utils.c
GNL_OBJ		= $(GNL_SRC:%.c=$(OBJ_DIR)/gnl/%.o)

MLX_DIR		= minilibx-linux

# **************************************************************************** #

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif

ifeq ($(UNAME), Darwin)
	CFLAGS += -D OSX
	MLX_FLAGS =
endif

# *****************************************************************************#

SRC = \
	main.c \
	parse/parse.c \
	parse/parse_line.c \
	parse/parse_colors.c \
	player/player_init.c \
	map/map.c \
	map/map_load.c \
	map/map_validate.c \
	utils/utils.c \
	scene/scene.c \
	scene/color.c

SRC := $(addprefix $(SRC_DIR)/,$(SRC))

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:.o=.d)
DEP += $(GNL_OBJ:.o=.d)

#*****************************************************************************#

GREEN	= \033[0;92m
BLUE	= \033[0;94m
RED		= \033[0;91m
RESET	= \033[0m

#***************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(GNL_OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -c $< -o $@

$(OBJ_DIR)/gnl/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling: $<$(RESET)"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)Object files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)Executable removed$(RESET)"

re: fclean all

norm:
	@norminette $(SRC_DIR) $(INC_DIR)
	@make norm -C $(LIBFT_DIR)

run: all
	@./$(NAME)

valgrind: all
	@valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		./$(NAME)

-include $(DEP)

.PHONY: all clean fclean re norm run valgrind
