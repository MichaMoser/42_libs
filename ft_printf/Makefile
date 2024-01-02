# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmoser <mmoser@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/23 16:04:31 by mmoser        #+#    #+#                  #
#    Updated: 2023/11/23 16:04:32 by mmoser        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	:= libftprintf.a

LIBFT	:= libft/libft.a

SRC 	:= ft_printf.c ft_flags.c ft_output.c ft_numconv.c
OBJ		:= $(SRC:.c=.o)

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror

RM		:= rm -f

all: $(NAME)

bonus: all

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(LIBFT):
	make -C $(@D)

clean:
	make -C $(dir $(LIBFT)) clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

info-%:
	$(MAKE) --dry-run --always-make $*

print-%:
	$(info $($*))

.PHONY: all clean fclean
