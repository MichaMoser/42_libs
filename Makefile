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

NAME		:= libft.a

CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -g 
RM			:= rm -rf

SRC_DIR		:= src
BUILD_DIR	:= .build

# ---------------------------------------------------------------------------- #
LIBFT_DIR	:= libft
PF_DIR		:= ft_printf
GNL_DIR		:= get_next_line
# ---------------------------------------------------------------------------- #
LIBFT_SRCS	:= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			   ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			   ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			   ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			   ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			   ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			   ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstiter.c \
			   ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstmap.c ft_lstsize.c
PF_SRCS		:= ft_printf.c ft_flags.c ft_output.c ft_numconv.c
GNL_SRCS	:= get_next_line.c get_next_line_utils.c
# ---------------------------------------------------------------------------- #
LIBFT_SRCS	:= $(LIBFT_SRCS:%=$(SRC_DIR)/$(LIBFT_DIR)/%)
PF_SRCS		:= $(PF_SRCS:%=$(SRC_DIR)/$(PF_DIR)/%)
GNL_SRCS	:= $(GNL_SRCS:%=$(SRC_DIR)/$(GNL_DIR)/%)
# ---------------------------------------------------------------------------- #
LIBFT_OBJS	:= $(LIBFT_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
PF_OBJS		:= $(PF_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
GNL_OBJS	:= $(GNL_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(LIBFT_OBJS) $(PF_OBJS) $(GNL_OBJS)
	ar rcs $@ $^
	@printf "$(CREATED)" $(NAME) $(CUR_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
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
