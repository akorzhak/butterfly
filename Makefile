# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 18:35:56 by akorzhak          #+#    #+#              #
#    Updated: 2018/01/13 18:35:58 by akorzhak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAG = -Wno-format-invalid-specifier -Wno-format -Wno-macro-redefined\
	-Wno-implicitly-unsigned-literal
LIB = libft/libft.a
NAME = libftprintf.a
OBJ = ft_printf.o ft_addsize.o ft_addflags.o ft_printarg.o ft_printnb.o\
	ft_get_unb.o ft_get_snb.o
# macro INCLUDE, on which the .c files depend. 
INCLUDE = libftprintf.h

.PHONY: all clean fclean
# a rule that applies to all files ending with the .o suffix. 
# the .o file depends upon the .c version of the file and the INCLUDE.
# automatic variables $<: the name of the prerequisite (a .c file)
%.o: %.c $(INCLUDE)
	$(C) $(CFLAG) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) $(LFLAG) $(LIB)
	ranlib $(NAME)
clean:
	/bin/rm -f $(OBJ) *~ 
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
