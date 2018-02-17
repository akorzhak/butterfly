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

CFLAG = -Wall -Wextra -Werror

LIBDIR = libft

LIB = $(LIBDIR)/libft.a

SRCDIR = src

SRC = ft_printf.c ft_addsize.c ft_addflags.c ft_printarg.c ft_printnb.c\
	ft_get_unb.c ft_get_snb.c ft_unicode.c ft_intlen.c ft_printc.c\
	ft_prints.c ft_zero_plus_space.c ft_print_percent.c ft_put.c ft_min.c

IDIR = includes

INC = $(IDIR)/libftprintf.h

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean

%.o: $(SRCDIR)/%.c
	@$(C) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@cp $(LIB) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo libftprintf.a has been successfully created :')'

clean:
	@make clean -C $(LIBDIR)
	@/bin/rm -f $(OBJ) *~
	@echo object files have been removed

fclean: clean
	@make fclean -C $(LIBDIR)
	@/bin/rm -f $(NAME)
	@echo libftprintf.a has been removed :'('

re: fclean all
