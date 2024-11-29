# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 18:50:41 by mokariou          #+#    #+#              #
#    Updated: 2024/11/01 17:57:31 by mokariou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBRARY = so_long.a
EXECUTABLE = so_long

SRC = src/check_map.c src/check_map_angles.c src/creating_cpy.c src/destroy_free.c src/draw_map_p1.c src/draw_map_p2.c \
      src/ft_actions.c src/init_map.c src/is_game_if.c src/load_img.c src/map_boundry.c src/move_pics.c src/so_long.c \
      inc/get_next_line/get_next_line.c inc/get_next_line/get_next_line_utils.c \
      inc/printf/ft_address.c inc/printf/ft_print_hex.c inc/printf/ft_printf.c inc/printf/ft_unsigned.c \
      inc/printf/printnum.c inc/printf/putstr.c \
      inc/libft/ft_atoi.c inc/libft/ft_bzero.c inc/libft/ft_calloc.c inc/libft/ft_isalnum.c inc/libft/ft_isalpha.c \
      inc/libft/ft_isascii.c inc/libft/ft_isdigit.c inc/libft/ft_isprint.c inc/libft/ft_itoa.c inc/libft/ft_lstadd_back_bonus.c \
      inc/libft/ft_lstadd_front_bonus.c inc/libft/ft_lstclear_bonus.c inc/libft/ft_lstdelone_bonus.c \
      inc/libft/ft_lstiter_bonus.c inc/libft/ft_lstlast_bonus.c inc/libft/ft_lstmap_bonus.c \
      inc/libft/ft_lstnew_bonus.c inc/libft/ft_lstsize_bonus.c inc/libft/ft_memchr.c \
      inc/libft/ft_memcmp.c inc/libft/ft_memcpy.c inc/libft/ft_memmove.c inc/libft/ft_memset.c \
      inc/libft/ft_putchar_fd.c inc/libft/ft_putendl_fd.c inc/libft/ft_putnbr_fd.c \
      inc/libft/ft_putstr_fd.c inc/libft/ft_split.c inc/libft/ft_strchr.c \
      inc/libft/ft_strdup.c inc/libft/ft_striteri.c inc/libft/ft_strjoin.c \
      inc/libft/ft_strlcat.c inc/libft/ft_strlcpy.c inc/libft/ft_strlen.c inc/libft/ft_strmapi.c \
      inc/libft/ft_strncmp.c inc/libft/ft_strnstr.c inc/libft/ft_strrchr.c inc/libft/ft_strtrim.c \
      inc/libft/ft_substr.c inc/libft/ft_tolower.c inc/libft/ft_toupper.c

OBJ = $(SRC:.c=.o)

all: $(LIBRARY) $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY): $(OBJ)
	ar rcs $(LIBRARY) $(OBJ)


$(EXECUTABLE): $(LIBRARY)
	$(CC) $(CFLAGS) $(OBJ) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(EXECUTABLE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBRARY) $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re	