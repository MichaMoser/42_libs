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

LIBFT	:= ../libft/libft.a

INCS	:= ../libft

SRC 	:= ft_printf.c ft_flags.c ft_output.c ft_numconv.c

OBJ_DIR	:= .obj
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror $(addprefix -I, $(INCS)) -g

RM		:= rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(dir $(LIBFT)).obj/*.o $(OBJ_DIR)
	ar rcs $(NAME) $(OBJ_DIR)/*.o
	@printf "$(CREATED)" $@ $(CUR_DIR)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(@D)

clean:
	make -C $(dir $(LIBFT)) clean
	$(RM) $(OBJ_DIR)
	@printf "$(REMOVED)" $(OBJ_DIR) $(CUR_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	@printf "$(REMOVED)" $(NAME) $(CUR_DIR)
	@printf "$(REMOVED)" $(LIBFT) $(CUR_DIR)

re: fclean all

info-%:
	$(MAKE) --dry-run --always-make $*

print-%:
	$(info $($*))

bonus: all

.PHONY: all clean fclean

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

CUR_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
REMOVED	:= $(MAGENTA) $(BOLD) REMOVED %s (%s) $(RESET)\n\n
CREATED	:= $(GREEN) $(BOLD) CREATED %s (%s) $(RESET)\n\n
UPDATED	:= $(GREEN) $(BOLD) CREATED OR UPDATED %s (%s) $(RESET)\n\n
