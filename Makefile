# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 12:51:20 by ecruz-go          #+#    #+#              #
#    Updated: 2022/03/16 13:25:18 by ecruz-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long
PROG	= so_long

MAP_SRC	= map_reader.c map_utils.c mpa_generator.c
SRCS 	= $(MAP_SRC) so_long.c events.c messages.c
SRCS_F 	= sources/
OBJS 	= ${SRCS:.c=.o} ${GNL:.c=.o}
OBJS_F	= _objFiles/
MAIN	= sources/so_long.c

HEADER	= -I./includes/so_long.h

# --- LIBFT ---
GNL = get_next_line.c get_next_line_utils.c
SRC_GNL = $(addprefix get_next_line/, $(GNL))

# --- LIBFT ---
LIBFT_A = libft.a
LIBF_DIR = Libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

# --- COMPILER ---
CC 		 = gcc
CFLAGS 	 = -Wall -Wextra -Werror
DBGFLAGS = -g -fsanitize=address
MINILIBX = -l mlx -framework OpenGL -framework AppKit

# --- COLORS ---
NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

# --- RULES ---
all:		$(NAME)

$(NAME):

					@echo $(CURSIVE)$(GRAY) "	- Creating object directory..." $(NONE)
					@mkdir -p $(OBJS_F)
					@echo $(CURSIVE)$(GRAY) "	- Making object files..." $(NONE)
					@$(CC) $(CFLAGS) -c $(addprefix $(SRCS_F), $(SRCS)) $(SRC_GNL)
					@echo $(CURSIVE)$(GRAY) "	- Moving object files to $(OBJS_F)..." $(NONE)	
					@mv $(OBJS) $(OBJS_F)
					@echo $(CURSIVE)$(GRAY) "	- Compiling Libft..." $(NONE)
					@make -C $(LIBF_DIR)
					@echo $(CURSIVE)$(GRAY) "	- Compiling $(NAME)..." $(NONE)
					@$(CC) $(CFLAGS) $(addprefix $(OBJS_F), $(OBJS)) $(LIBFT) $(MINILIBX) -o $(NAME)
					@echo $(GREEN)"	- so_long Compiled -"$(NONE)

clean:
					@rm -rf $(OBJS_F)
					@rm -f ${OBJS}

fclean: 	clean
					@rm -f $(NAME)
					@rm -f ${PROG}
					@echo "\n\033[31mDeleting EVERYTHING!\n"

re:			fclean all

.PHONY: all clean fclean re