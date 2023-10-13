# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 22:14:06 by tayou             #+#    #+#              #
#    Updated: 2023/06/04 23:32:11 by tayou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRC_FILE = pipex \
		   check_argc \
		   make_initial_setting \
		   get_cmd_array get_cmd_directory_array \
		   execute_cmd_in_parallel \
		   execute_parent_process execute_child_process \
		   get_cmd_path \
		   utils \
		   free_function
BONUS_FILE = pipex \
		   check_argc \
		   check_heredoc_exist \
		   make_initial_setting \
		   get_cmd_array get_cmd_directory_array make_heredoc_file \
		   execute_cmd_in_parallel \
		   execute_parent_process execute_child_process \
		   get_cmd_path \
		   utils \
		   free_function 

SRC = $(addsuffix .c, $(SRC_FILE))
SRC_BONUS = $(addsuffix _bonus.c, $(BONUS_FILE))
OBJ = $(addsuffix .o, $(SRC_FILE))
OBJ_BONUS = $(addsuffix _bonus.o, $(BONUS_FILE))

all : $(NAME)

clean : 
	make -C $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(OBJ) $(OBJ_BONUS) 

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME) $(NAME_BONUS)

re : fclean all

bonus : $(NAME_BONUS)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS) -o $(NAME) $^

$(NAME_BONUS) : $(LIBFT) $(OBJ_BONUS)
	$(CC) $(CCFLAGS) -o $(NAME_BONUS) $^

$(LIBFT) : 
	make bonus -C $(LIBFT_DIR) all
			   
%.o : %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

.PHONY : all clean fclean re libft bonus
