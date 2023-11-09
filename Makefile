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
COMP 	=	clang
CFLAGS 	=	-Wall -Werror -Wextra
HEAD	=	includes/
libft	=	libft/
SRC		=	ft_printf.c\
			ft_printf_utils.c\
			ft_printf_fomat_utils.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	@$(COMP) -g -fPIE $(CFLAGS) -o $@ -c $< -I $(HEAD)

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
	@clang -g test.c libftprintf.a -o test
#	@valgrind --track-origins=yes --tool=memcheck --track-fds=yes --leak-check=full -s --show-leak-kinds=all ./test
	@./test
test2 : re
#	@cp -rf ../tester2 ./tester2
#	@make -C ./tester2
#	@cd ./tester2 && ./tester m
#	@rm -rf ./tester2
#	@cp -rf ../Tester ./Tester
#	@make -C ./Tester
#	@rm -rf ./Tester
	@cp -rf ../pftTest ./pftTest
	@make -C ./pftTest
	@cd ./pftTest && ./test
	@cp ./pftTest/results.txt ./results.txt
	@rm -rf ./pftTest


re : fclean all

.PHONY: all fclean clean re


