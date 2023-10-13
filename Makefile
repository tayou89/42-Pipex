# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 22:14:06 by tayou             #+#    #+#              #
#    Updated: 2023/06/01 11:13:02 by tayou            ###   ########.fr        #
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
		   open_files \
		   execute_cmd_by_parallel_process \
		   check_cmd_accessibility \
		   utils \
		   execute_error_process free_function 
BONUS_FILE = pipex \
		   check_argc \
		   check_heredoc_exist \
		   make_initial_setting \
		   get_cmd_array get_cmd_directory_array \
		   open_files \
		   read_line_and_write_to_heredoc \
		   execute_cmd_by_parallel_process \
		   execute_child_process \
		   check_cmd_accessibility \
		   utils \
		   execute_error_process free_function 

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
