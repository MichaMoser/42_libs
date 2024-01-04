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

NAME		:= 42lib.a

LIB_DIR		:= \
			   libft \
			   ft_printf \
			   get_next_line

LIBS		:= \
			   libft/libft.a \
			   ft_printf/libftprintf.a \
			   get_next_line/libgetnextline.a

RM			:= rm -f

BUILD_DIR	:= .build

CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra -g

all: $(LIBS)

%.a:
	$(MAKE) -C $(@D)
	cp $(@D)/.obj/*.o $(BUILD_DIR)
	@printf "$(CREATED)" $@
	ar -rcs $(NAME) $(BUILD_DIR)/*.o
	@printf "$(UPDATED)" $(NAME)

clean:
	@for dir in $(dir $(LIBS)); \
		do $(MAKE) -C $$dir clean && printf "$(REMOVED_OBJECTS)" $$dir; done
	$(RM) $(BUILD_DIR)/*.o
	@printf "$(REMOVED_OBJECTS)" $(BUILD_DIR);

fclean: clean
	@for dir in $(dir $(LIBS)); \
		do $(MAKE) -C $$dir fclean && printf "$(REMOVED_ARCHIVE)" $$dir; done
	$(RM) $(NAME)
	@printf "$(REMOVED_ARCHIVE)" $(NAME);

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
REMOVED_OBJECTS	:= $(MAGENTA) $(BOLD) REMOVED .o FILES FROM %s $(RESET)\n
CREATED			:= $(GREEN) $(BOLD) CREATED %s $(RESET)\n\n
UPDATED			:= $(GREEN) $(BOLD) CREATED OR UPDATED %s $(RESET)\n\n
