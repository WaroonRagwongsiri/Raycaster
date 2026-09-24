# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waroon <waroon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/04 20:20:04 by waroonwork@       #+#    #+#              #
#    Updated: 2026/09/24 12:17:36 by waroon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	cub3D

CC				:=	cc
AR				:=	ar rcs
CFLAGS			:=	-Wall -Wextra -Werror -g3

# Linking differs per OS: macOS needs Apple frameworks instead of dl/pthread
UNAME			:=	$(shell uname)
ifeq ($(UNAME), Darwin)
GLFW_FLAGS		:=	$(shell pkg-config --libs glfw3 2>/dev/null \
						|| echo "-L/opt/homebrew/lib -lglfw")
LDFLAGS			:=	$(GLFW_FLAGS) -framework Cocoa -framework OpenGL \
					-framework IOKit -lm
else
LDFLAGS			:=	-ldl -lglfw -lGL -pthread -lm
endif

# Project
INC_DIR			:=	includes/
SRCS_DIR		:=	src/
SRCS_FILES		:=	main.c \
					graphics/gl_loader.c graphics/graphics_destroy.c graphics/graphics_init.c \
					graphics/present.c graphics/shader.c graphics/texture_load.c \
					map/map_access.c \
					parser/parse_color.c parser/parse_elements.c parser/parse_file.c parser/parse_map.c parser/parse_utils.c parser/validate_map.c \
					player/player_init.c player/player_input.c player/player_move.c player/player_rotate.c \
					render/draw_column.c render/ray_dda.c render/ray_init.c render/ray_projection.c render/ray_texture.c render/render_frame.c \
					utils/color.c
SRCS			:=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			:=	$(SRCS:.c=.o)

# Vendored single-header libs
LIBS_DIR		:=	libs/
STB_OBJ			:=	$(LIBS_DIR)stb_image_impl.o

# Libft
LIBFT_DIR		:=	libft/
LIBFT_INC_DIR	:=	$(LIBFT_DIR)includes/
LIBFT			:=	libft.a

# Get Next Line
GNL_DIR			:=	get_next_line/
GNL_INC_DIR		:=	$(GNL_DIR)
GNL				:=	libgnl.a
GNL_SRCS		:=	$(GNL_DIR)get_next_line_bonus.c \
					$(GNL_DIR)get_next_line_utils_bonus.c
GNL_OBJS		:=	$(GNL_SRCS:.c=.o)

# Include flags
CPPFLAGS		:=	-I$(INC_DIR) \
					-I$(LIBFT_INC_DIR) \
					-I$(GNL_INC_DIR) \
					-I$(LIBS_DIR)

# Main rule
# Build order:
# 1. Libft
# 2. GNL
# 3. Project source objects
# 4. Vendored stb_image
# 5. Final executable
all				:
	$(MAKE) $(LIBFT)
	$(MAKE) $(GNL)
	$(MAKE) $(OBJS)
	$(MAKE) $(STB_OBJ)
	$(MAKE) $(NAME)

# Final executable
$(NAME)			:	$(OBJS) $(STB_OBJ) $(LIBFT) $(GNL) Makefile
	$(CC) $(CFLAGS) $(OBJS) $(STB_OBJ) $(LIBFT) $(GNL) \
		$(LDFLAGS) -o $@

# Project object files
$(SRCS_DIR)%.o	:	$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Vendored stb_image
$(LIBS_DIR)%.o	:	$(LIBS_DIR)%.c
	$(CC) -g3 -I$(LIBS_DIR) -c $< -o $@

# Libft
libft			:	$(LIBFT)

$(LIBFT)		:
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)libft.a $(LIBFT)

# Get Next Line
gnl				:	$(GNL)

$(GNL)			:	$(GNL_OBJS)
	$(AR) $@ $^

$(GNL_DIR)%.o	:	$(GNL_DIR)%.c
	$(CC) $(CFLAGS) -I$(GNL_INC_DIR) -c $< -o $@

# Cleaning
clean			:
	rm -f $(OBJS)
	rm -f $(STB_OBJ)
	rm -f $(GNL_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean			:	clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(GNL)

re				:	fclean
	$(MAKE) all

bonus			:	all

.PHONY			:	all clean fclean re bonus libft gnl
