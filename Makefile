# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 11:22:08 by mmoser            #+#    #+#              #
#    Updated: 2024/06/20 14:21:20 by mmoser           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -g
RM			:= rm -rf

# ---------------------------------------------------------------------------- #
SRC_DIR		:= src
LIBFT_DIR	:= $(SRC_DIR)/libft
PF_DIR		:= $(SRC_DIR)/ft_printf
GNL_DIR		:= $(SRC_DIR)/get_next_line

# ---------------------------------------------------------------------------- #
LIBFT_SRCS	:= $(shell find $(LIBFT_DIR) -iname "*.c")
PF_SRCS		:= $(shell find $(PF_DIR) -iname "*.c")
GNL_SRCS	:= $(shell find $(GNL_DIR) -iname "*.c")

# ---------------------------------------------------------------------------- #
BUILD_DIR	:= .build
LIBFT_OBJS	:= $(LIBFT_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
PF_OBJS		:= $(PF_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
GNL_OBJS	:= $(GNL_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(PF_OBJS) $(GNL_OBJS)
	@printf "\n"
	ar rcs $@ $^
	@printf "$(CREATED)" $(NAME) $(CUR_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD_DIR)
	@printf "$(REMOVED)" $(BUILD_DIR) $(CUR_DIR)

fclean: clean
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
