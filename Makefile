# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuc <asuc@student.42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 17:42:16 by asuc              #+#    #+#              #
#    Updated: 2023/08/12 17:42:16 by asuc             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BGreen	=	$(shell echo "\033[1;32m")
RESET	=	$(shell echo "\033[0m")
BRed	=	$(shell echo "\033[1;31m")
NAME 	=	libftprintf.a
COMP 	=	cc
CFLAGS 	=	-Wall -Werror -Wextra
HEAD	=	includes/
libft	=	libft/
SRC		=	ft_printf.c\
			ft_printf1.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	@$(COMP) -fPIE $(CFLAGS) -o $@ -c $< -I $(HEAD)

$(NAME) : $(OBJ)
	@make --no-print-directory -C $(libft)
	@cp libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJ)
	@echo "$(BGreen)Compilation OK$(RESET)"

clean :
	@make clean --no-print-directory -C $(libft)
	@rm -f $(OBJ)
	@echo "$(BRed)Erase .o files$(RESET)"


fclean : clean
	@make fclean --no-print-directory -C $(libft)
	@rm -f $(NAME) libft.a
	@echo "$(BRed)Erase $(NAME) and libft.a$(RESET)"

test : re
	@gcc -g -Werror -Wextra -Wall test.c ft_printf.c ft_printf1.c -L./libft -lft -o test && ./test

test2 : re
	@cp -rf ../tester2 ./tester2
	@make -C ./tester2
	@cd ./tester2 && ./tester m
	@rm -rf ./tester2
	@cp -rf ../Tester ./Tester
	@make -C ./Tester
	@rm -rf ./Tester
#	@cp -rf ../pftTest ./pftTest
#	@make -C ./pftTest
#	@cd ./pftTest && ./test
#	@rm -rf ./pftTest


re : fclean all

.PHONY: all fclean clean re


