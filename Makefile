# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 11:22:08 by mmoser            #+#    #+#              #
#    Updated: 2024/01/03 11:57:11 by mmoser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= lib42.a

LIB_DIR		:= \
			   libft \
			   ft_printf \
			   get_next_line

LIBS		:= \
			   libft/libft.a \
			   ft_printf/libftprintf.a \
			   get_next_line/libgetnextline.a

RM			:= rm -rf

BUILD_DIR	:= .build

CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -g

all: $(LIBS)

%.a:
	$(MAKE) -C $(@D)
	mkdir -p $(BUILD_DIR)
	cp $(@D)/.obj/*.o $(BUILD_DIR)
	ar -rcs $(NAME) $(BUILD_DIR)/*.o
	@printf "$(UPDATED)" $(NAME) $(CUR_DIR)

clean:
	@for dir in $(dir $(LIBS)); \
		do $(MAKE) -C $$dir clean; done
	$(RM) $(BUILD_DIR)
	@printf "$(REMOVED)" $(BUILD_DIR)  $(CUR_DIR)

fclean: clean
	@for dir in $(dir $(LIBS)); \
		do $(MAKE) -C $$dir fclean; done
	$(RM) $(NAME)
	@printf "$(REMOVED)" $(NAME)  $(CUR_DIR)

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

CUR_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
REMOVED	:= $(MAGENTA) $(BOLD) REMOVED %s (%s) $(RESET)\n\n
CREATED	:= $(GREEN) $(BOLD) CREATED %s (%s) $(RESET)\n\n
UPDATED	:= $(GREEN) $(BOLD) CREATED OR UPDATED %s (%s) $(RESET)\n\n
