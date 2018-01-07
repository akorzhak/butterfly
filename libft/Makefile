# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 22:20:50 by akorzhak          #+#    #+#              #
#    Updated: 2017/10/27 22:20:52 by akorzhak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
CFLAG = -Wall -Wextra -Werror
NAME = libft.a
OBJ = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o\
ft_memchr.o ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o\
ft_strncpy.o ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o\
ft_strrchr.o ft_strstr.o ft_strjoin.o ft_strdel.o ft_strnstr.o\
ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o\
ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o\
ft_memalloc.o ft_memdel.o ft_strnew.o ft_strclr.o ft_striter.o\
ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o\
ft_strsub.o ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o\
ft_putstr.o ft_putendl.o ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o\
ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o\
ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_strrev.o ft_strlcpy.o\
ft_itoa_base.o ft_split_white.o ft_print_bits.o ft_reverse_bits.o
# macro INCLUDE, on which the .c files depend. 
INCLUDE = libft.h

.PHONY: all clean fclean
# a rule that applies to all files ending with the .o suffix. 
# the .o file depends upon the .c version of the file and the INCLUDE.
# automatic variables $<: the name of the prerequisite (a .c file)
%.o: %.c $(INCLUDE)
	$(C) $(CFLAG) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	/bin/rm -f $(OBJ) *~ 
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
