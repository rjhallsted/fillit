# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 09:37:14 by rhallste          #+#    #+#              #
#    Updated: 2017/10/05 15:08:44 by rhallste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	fillit
LIBNAME		=	libft.a

TESTFILE	=	valid11

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

LIBLIST		=	ft_bzero				\
				ft_free_2d_array		\
				ft_memalloc				\
				ft_memset				\
				ft_putchar				\
				ft_putchar_fd			\
				ft_putstr				\
				ft_putstr_fd			\
				ft_strcpy				\
				ft_strdup				\
				ft_strsub				\
				ft_strlen				\
				ft_strncat				\
				ft_strncpy				\
				ft_strnew				\
				ft_swap

MAINLIST	=	validate_input			\
				tetri_split				\
				read_input				\
				coords					\
				main					\
				backtracking			\
				finder					

LIBSRCS		=	$(addsuffix .c, $(LIBLIST))
LIBOBJS		=	$(addsuffix .o, $(LIBLIST))

MAINSRCS	=	$(addsuffix .c, $(MAINLIST))
MAINOBJS	=	$(addsuffix .o, $(MAINLIST))

all: $(NAME)

$(LIBOBJS): $(LIBSRCS)

$(MAINOBJS): $(MAINSRCS)

$(LIBNAME): $(LIBOBJS)
	ar rcs $(LIBNAME) $(LIBOBJS)

$(NAME): $(LIBNAME) $(MAINOBJS)
	$(CC) $(CFLAGS) $(MAINOBJS) $(LIBNAME) -o $(NAME)

clean:
	@rm -rf $(MAINOBJS) $(LIBOBJS) $(TESTOBJS)

fclean: clean
	@rm -rf $(NAME) $(LIBNAME) t

re: fclean all

.SILENT: $(LIBOBJS) $(MAINOBJS)