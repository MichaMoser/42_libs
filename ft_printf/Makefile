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

RM		:= rm -f

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(dir $(LIBFT)).obj/*.o $(OBJ_DIR)
	ar rcs $(NAME) $(OBJ_DIR)/*.o

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(@D)
	@printf "$(CREATED)" $@

clean:
	make -C $(dir $(LIBFT)) clean
	$(RM) $(OBJ_DIR)/*.o

fclean: clean
	$(RM) $(NAME) $(LIBFT)

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

REMOVED_ARCHIVE	:= $(MAGENTA) $(BOLD) REMOVED .a FILE FROM %s $(RESET)\n
REMOVED_OBJECTS	:= $(MAGENTA) $(BOLD) REMOVED .o FILE FROM %s $(RESET)\n
CREATED			:= $(GREEN) $(BOLD) CREATED %s $(RESET)\n\n
