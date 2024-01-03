# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 11:15:36 by mmoser            #+#    #+#              #
#    Updated: 2024/01/03 11:59:24 by mmoser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libgetnextline.a

LIBFT	:= ../libft/libft.a

INCS	:= ../libft

SRCS	:= get_next_line.c get_next_line_utils.c

OBJ_DIR	:= .obj
OBJS	:= $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra -g $(addprefix -I ,$(INCS))

RM		:= rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(dir $(LIBFT)).obj/*.o $(OBJ_DIR)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(@D)
	@printf "$(CREATED)" $@

clean:
	$(RM) $(OBJ_DIR)/*.o

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

info-%:
	$(MAKE) --dry-run --always-make $*

print-%:
	$(info $($*))

.PHONY: clean fclean re

# ----------------------------------- colors --------------------------------- #

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

# ----------------------------------- messages ------------------------------- #

REMOVED_ARCHIVE	:= $(MAGENTA) $(BOLD) REMOVED .a FILE FROM %s $(RESET)\n
REMOVED_OBJECTS	:= $(MAGENTA) $(BOLD) REMOVED .o FILE FROM %s $(RESET)\n
CREATED			:= $(GREEN) $(BOLD) CREATED %s $(RESET)\n\n
