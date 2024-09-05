# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 14:25:51 by vstineau          #+#    #+#              #
#    Updated: 2024/08/20 14:57:46 by wnocchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -g -O2 -fno-builtin
SRCS = ft_isalpha.c \
			 ft_isdigit.c \
			 ft_isalnum.c \
			 ft_isascii.c \
			 ft_isprint.c \
			 ft_strlen.c \
			 ft_abs.c \
			 ft_memset.c \
			 ft_bzero.c \
			 ft_memcpy.c \
			 ft_memmove.c \
			 ft_strcpy.c \
			 ft_strlcpy.c \
			 ft_strlcat.c \
			 ft_toupper.c \
			 ft_tolower.c \
			 ft_strchr.c \
			 ft_strrchr.c \
			 ft_strncmp.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_strnstr.c \
			 ft_atoi.c \
			 ft_calloc.c \
			 ft_realloc.c \
			 ft_strdup.c \
			 ft_strndup.c \
			 ft_substr.c \
			 ft_strjoin.c \
			 ft_strtrim.c \
			 ft_split.c \
			 ft_itoa.c \
			 ft_strmapi.c \
			 ft_striteri.c \
			 ft_putchar_fd.c \
			 ft_putstr_fd.c \
			 ft_putendl_fd.c \
			 ft_putnbr_fd.c \
			 get_next_line.c get_next_line_utils.c \
			 ft_lstnew.c \
			 ft_lstadd_front.c \
			 ft_lstsize.c \
			 ft_lstlast.c \
			 ft_lstadd_back.c \
			 ft_lstdelone.c \
			 ft_lstclear.c \
			 ft_lstiter.c \
			 ft_lstmap.c \
			 ft_printf.c type_is_char.c type_is_string.c type_is_pointer.c \
			 type_is_int.c type_is_unsigned_decimal.c type_is_lower_hexadecimal.c \
			 type_is_upper_hexadecimal.c type_is_percent.c ft_strleni.c ft_hexalen.c \
			 ft_intlen.c ft_putnbr_base.c ft_putnbr.c ft_putchar.c print_types.c \
			 is_type.c ft_ulen.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF)
	ar -rcs $(NAME) $(OBJS) $(INCLUDES)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

-include $(OBJECTS:.o=.d)

clean:
	rm -rf $(OBJS) $(OBJS:.o=.d)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
