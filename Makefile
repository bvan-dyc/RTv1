# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 22:53:24 by bvan-dyc          #+#    #+#              #
#    Updated: 2017/11/07 15:47:48 by bvan-dyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=rtv1

CFLAGS=-Wall -Wextra -Werror

SRC=src/main.c src/keyhook.c src/tools.c src/draw.c src/vectortools.c \
src/read.c src/get_next_line.c src/parser.c src/intersections.c \
src/parseforms.c src/drawtools.c

OBJS=obj/main.o obj/keyhook.o obj/tools.o obj/draw.o obj/vectortools.o \
obj/read.o obj/get_next_line.o obj/parser.o obj/intersections.o \
obj/parseforms.o obj/drawtools.o

$(NAME): $(OBJS)
	@printf "\n"
	@make -C libft/
	@gcc $(CFLAGS) -I /usr/X11/include -L libft/ -lft -l mlx -L \
	/usr/X11/lib -framework OpenGL -framework AppKit $(SRC) -o $(NAME)
	@printf '\033[32m -> %s\n\033[0m' "rtv1 Compiled!"

obj/%.o: src/%.c
	@mkdir -p obj
	@gcc $(CFLAGS) -I /usr/X11/include -c $< -o $@
	@printf '\033[0m[/] %s\n\033[0m' "$<"

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJS)
	@printf '\033[0m[/] %s\n\033[0m' "cleaned RTV1"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME) rm -rf $(OBJS)
	@printf '\033[0m[/] %s\n\033[0m' "fcleaned RTV1"
	@printf "\n"

re: fclean all

.PHONY: clean fclean
