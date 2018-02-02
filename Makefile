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

NAME = libftprintf.a

C = gcc

CFLAG = -Wno-format-invalid-specifier -Wno-format -Wno-macro-redefined\
	-Wno-implicitly-unsigned-literal

LIBDIR = libft

#LIBOBJ = $(LIBDIR)/*.o
LIB = $(LIBDIR)/libft.a

SRCDIR = src

SRC = ft_printf.c ft_addsize.c ft_addflags.c ft_printarg.c ft_printnb.c\
	ft_get_unb.c ft_get_snb.c ft_unicode.c ft_intlen.c

IDIR = includes

INC = $(IDIR)/libftprintf.h

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean

%.o: $(SRCDIR)/%.c
	$(C) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR)
	cp $(LIB) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make clean -C $(LIBDIR)
	/bin/rm -f $(OBJ) *~

fclean: clean
	make fclean -C $(LIBDIR)
	/bin/rm -f $(NAME)

re: fclean all
