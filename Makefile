# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 16:44:11 by eabdelha          #+#    #+#              #
#    Updated: 2022/01/18 16:44:13 by eabdelha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNAME = checker
NAME_LIBFT = libft.a

LIBFT_PATH = ./libft
SRC_PATH = ./push_swap_src/
BSRC_PATH = ./push_swap_bonus/

FOBJ_SRC = object_files_src
FOBJ_BONUS = object_files_bonus

OBJECT_PATH = ./object_files_src/
BOBJECT_PATH = ./object_files_bonus/

INCLUDE = $(SRC_PATH)/push_swap.h
OPS_INCLUDE = $(SRC_PATH)/operations.h
BINCLUDE = $(BSRC_PATH)/checker.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC	=	push_swap_algo.c		\
		push_swap.c				\
		functions_ops.c			\
		sort_less_six.c			\
		sort_utiles.c			\
		check_numbers.c			\
		quick_sort.c			\
		push.c				\
		swap.c	  			\
		rotate.c			\
		r_rotate.c

BSRC =  checker.c      		\
		checker_utils.c    	\
		check_result.c		\
		functions_ops.c		\
		execute_ops.c		\
		quick_sort.c		\
		get_next_line.c

OBJECTS = $(addprefix $(OBJECT_PATH), $(SRC:.c=.o))
BOBJECTS = $(addprefix $(BOBJECT_PATH), $(BSRC:.c=.o))

.PHONY : all bonus clean fclean re

all: $(NAME)
 
$(NAME): $(FOBJ_SRC) $(OBJECTS) $(LIBFT_PATH)/$(NAME_LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_PATH)/$(NAME_LIBFT) -o $(NAME)

bonus : $(BNAME) $(BOBJECTS)

$(BNAME): $(FOBJ_BONUS) $(BOBJECTS) $(LIBFT_PATH)/$(NAME_LIBFT)
	$(CC) $(CFLAGS) $(BOBJECTS) $(LIBFT_PATH)/$(NAME_LIBFT) -o $(BNAME)

$(OBJECT_PATH)%.o : $(SRC_PATH)%.c $(INCLUDE) $(OPS_INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

$(BOBJECT_PATH)%.o : $(BSRC_PATH)%.c $(BINCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT_PATH)/$(NAME_LIBFT) : $(NAME_LIBFT)

$(NAME_LIBFT) :
	@make -C $(LIBFT_PATH)

$(FOBJ_SRC) : 
	@mkdir $@

$(FOBJ_BONUS) : 
	@mkdir $@

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJECTS) $(BOBJECTS)
	@rm -rf $(FOBJ_BONUS) $(FOBJ_SRC)

fclean: clean
	@make fclean -C $(LIBFT_PATH) 
	@rm -f $(NAME) $(BNAME)

re: fclean all
