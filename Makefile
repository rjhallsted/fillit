#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 09:37:14 by rhallste          #+#    #+#              #
#    Updated: 2017/10/02 12:33:40 by rhallste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= 	fillit
LIBNAME		=	libft.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

LIBLIST		=	ft_bzero				\
				ft_free_2d_array		\
				ft_lst_swap				\
				ft_lstlen				\
				ft_memalloc				\
				ft_putchar				\
				ft_putchar_fd			\
				ft_putstr				\
				ft_putstr_fd			\
				ft_strcpy				\
				ft_strdup				\
				ft_strnew				\

MAINLIST	=	backtracking			\
				check_input				\
				list					\
				main					\
				read_input				\
				tetriminos_split		

LIBSRCS		=	$(addsuffix .c, $(LIBLIST))
LIBOBJS		=	$(addsuffix .o, $(LIBLIST))

MAINSRCS	=	$(addsuffix .c, $(MAINLIST))
MAINOBJS	=	$(addsuffix .o, $(MAINLIST))


all: $(NAME)

$(LIBOBJS): $(LIBSRCS)

$(MAINOBJS): $(MAINSRCS)

$(LIBNAME): $(LIBOBJS)
	@ar rcs $(LIBNAME) $(LIBOBJS)

$(NAME): $(LIBNAME) $(MAINOBJS)

clean:
	@rm -rf $(MAINOBJS) $(LIBOBJS)

fclean: clean
	@rm -rf $(NAME) $(LIBNAME)

re: fclean all

.SILENT: $(LIBOBJS) $(MAINOBJS)