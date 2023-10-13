# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 22:14:06 by tayou             #+#    #+#              #
#    Updated: 2023/05/21 22:14:44 by tayou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRC_FILE = pipex \
		   check_argc get_initial_data get_initial_cmd_array \
		   execute_cmd \
		   utils_1 utils_2 \
		   handle_error free_function

SRC = $(addsuffix .c, $(SRC_FILE))
OBJ = $(addsuffix .o, $(SRC_FILE))

all : $(NAME)

clean : 
	make -C $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(OBJ) $(OBJ_BONUS) 

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS) -o $(NAME) $^ -g -fsanitize=address

$(LIBFT) : 
	make bonus -C $(LIBFT_DIR) all
			   
%.o : %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

.PHONY : all clean fclean re libft bonus
