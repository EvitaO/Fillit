# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-hou <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/08 20:38:49 by mvan-hou      #+#    #+#                  #
#    Updated: 2020/07/26 21:59:19 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main read check save board print free solve ft_strsub \
ft_memalloc ft_memcmp

FILEC = $(SRC:%=%.c)

HEADER = fillit.h

OBJ = main.o read.o check.o save.o board.o print.o free.o solve.o ft_strsub.o \
ft_memalloc.o ft_memcmp.o

COMP = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo Compiling files
	@$(COMP) -c -I.$(HEADER) $(FILEC)
	@$(COMP) -o $(NAME) $(OBJ) -I.$(HEADER)

clean:
	@echo Removing object files
	@rm -f $(OBJ)

fclean: clean
	@echo Removing binary file
	@rm -f $(NAME)

re: fclean all
