#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 22:53:24 by bvan-dyc          #+#    #+#              #
#    Updated: 2015/12/03 22:53:30 by bvan-dyc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=libft.a

CFLAGS=-Wall -Wextra -Werror

SRC= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
	ft_memset.c ft_putchar_fd.c ft_putchar.c ft_putendl.c ft_putnbr_fd.c \
	ft_putnbr.c ft_putstr_fd.c ft_putstr.c ft_strcat.c ft_strchr.c \
	ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
	ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncpy.c \
	ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
	ft_strstr.c ft_memalloc.c ft_strsub.c ft_strtrim.c ft_tolower.c \
	ft_toupper.c ft_memmove.c ft_putendl_fd.c ft_strncmp.c ft_lstiter.c \
	ft_wordcount.c ft_mapalloc.c ft_matalloc.c ft_lstdelone.c ft_lstdel.c \
	ft_numcount.c ft_findsign.c ft_stralloc.c ft_lstadd.c ft_lstnew.c \
	ft_lstmap.c ft_uabs.c ft_putstrtab.c ft_linelen.c convert_rgb.c \
	ft_atoicount.c ft_fmin.c rt_strjoin.c

OBJS= ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
	ft_isdigit.o ft_islower.o ft_isprint.o ft_isupper.o ft_itoa.o \
	ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o \
	ft_memset.o ft_putchar_fd.o ft_putchar.o ft_putendl.o ft_putnbr_fd.o \
	ft_putnbr.o ft_putstr_fd.o ft_putstr.o ft_strcat.o ft_strchr.o \
	ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o \
	ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o \
	ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncpy.o \
	ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o \
	ft_strstr.o ft_memalloc.o ft_strsub.o ft_strtrim.o ft_tolower.o \
	ft_toupper.o ft_memmove.o ft_putendl_fd.o ft_strncmp.o ft_lstiter.o \
	ft_wordcount.o ft_mapalloc.o ft_matalloc.o ft_lstdelone.o ft_lstdel.o \
	ft_numcount.o ft_findsign.o ft_stralloc.o ft_lstadd.o ft_lstnew.o \
	ft_lstmap.o ft_uabs.o ft_putstrtab.o ft_linelen.o convert_rgb.o \
	ft_atoicount.o ft_fmin.o rt_strjoin.o

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS) && ranlib $(NAME)
	@printf '\033[32m -> %s\n\033[0m' "Libft Created!"

%.o : %.c
		@gcc $(CFLAGS) -c $(SRC)

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@printf '\033[0m[/] %s\n\033[0m' "cleaned Libft"

fclean: clean
	@rm -rf $(NAME)
	@printf '\033[0m[/] %s\n\033[0m' "fcleaned Libft"

re: fclean all

.PHONY: clean fclean
