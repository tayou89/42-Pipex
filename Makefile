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

# Compile Commands
GCC = gcc
GCC_FLAGS = -Wall -Wextra -Werror
RM = rm
RM_FLAGS = -rf

# Exterior Libarary
LIBFT = ./libft/libft.a

# Path
LIBFT_PATH = libft/
SOURCE_PATH = sources/
OBJECT_PATH = objects/
MANDATORY_PATH = mandatory/
BONUS_PATH = bonus/
LIBFT_HEADER_PATH = libft/

# Source Name List
MANDATORY_SOURCE_NAME = pipex \
						check_argc \
						make_initial_setting \
						get_cmd_array get_cmd_directory_array \
						execute_cmd_in_parallel \
						execute_parent_process execute_child_process \
						get_cmd_path \
						utils \
						free_function

BONUS_SOURCE_NAME = pipex \
					check_argc \
					check_heredoc_exist \
					make_initial_setting \
					get_cmd_array get_cmd_directory_array make_heredoc_file \
					execute_cmd_in_parallel \
					execute_parent_process execute_child_process \
					get_cmd_path \
					utils \
					free_function 

# Sources
MANDATORY_SOURCES = \
	$(addprefix $(SOURCE_PATH)$(MANDATORY_PATH), $(addsuffix .c, $(MANDATORY_SOURCE_NAME)))
BONUS_SOURCES = \
	$(addprefix $(SOURCE_PATH)$(BONUS_PATH), $(addsuffix _bonus.c, $(BONUS_SOURCE_NAME)))

# Objects
MANDATORY_OBJECTS = \
	$(addprefix $(OBJECT_PATH)$(MANDATORY_PATH), $(addsuffix .o, $(MANDATORY_SOURCE_NAME)))
BONUS_OBJECTS = \
	$(addprefix $(OBJECT_PATH)$(BONUS_PATH), $(addsuffix _bonus.o, $(BONUS_SOURCE_NAME)))

# Make Commands
all : $(NAME)

$(NAME) : $(LIBFT) $(MANDATORY_OBJECTS)
	$(GCC) $(GCC_FLAGS) -o $(NAME) $^

clean : 
	make -C $(LIBFT_PATH) clean
	$(RM) $(RM_FLAGS) $(OBJECT_PATH)

fclean : clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(RM_FLAGS) $(NAME) $(NAME_BONUS)

re : fclean all

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(BONUS_OBJECTS)
	$(GCC) $(GCC_FLAGS) -o $(NAME_BONUS) $^

$(LIBFT): 
	make bonus -C $(LIBFT_PATH) all
			   
$(OBJECT_PATH)%.o : $(SOURCE_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -I$(LIBFT_HEADER_PATH) -o $@ -c $<

.PHONY : all clean fclean re libft bonus