# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 22:02:38 by caalbert          #+#    #+#              #
#    Updated: 2023/05/17 05:22:33 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -g -O3
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

# valgrind flags.
LFLAGS		= --leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes \
				--log-file=valgrind-out.txt \
				./push_swap 209 390 200 -10 -23 0 5

SRCDIR		= ./srcs/
OBJDIR		= ./objs/

SRC			= main.c \
				errors.c \
				manage_lists.c \
				operating_push.c \
				operating_reverse.c \
				operating_swap.c \
				operating_rotate.c \
				radix_algorithimn.c \
				sorting_biggest_numbers.c \
				sorting_small_numbers.c \
				tools_utils.c
OBJ			= $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))

CYAN			:= \033[1;36m
YELLOW			:= \033[1;33m
GREEN			:= \033[1;32m
RED				:= \033[1;31m
RESET			:= \033[0m

HEADER_NAME 	= +                   * $(NAME) Compiled!               #
all: $(NAME)

$(OBJDIR)%.o:	$(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	@echo ""
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@echo "------------------------------------------"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo ""
	@echo "${GREEN}\
\n/* ************************************************************************** */\
\n/*                                                                            */\
\n/*            :::      ::::::::                                               */\
\n/*          :+:      :+:    :+:                                               */\
\n/*        +:+ +:+         +:+                      DONE...                    */\
\n/*      +#+  +:+       +#+                                                    */\
\n/*    +#+#+#+#+#+   +#${HEADER_NAME}*/\
\n/*         #+#    #+#           By: caalbert <caalbert@student.42sp.org.br>   */\
\n/*        ###   ########.fr                                                   */\
\n/*                                                                            */\
\n/* ************************************************************************** */\n\
			${RESET}"
	@echo ""

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJDIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

leaks:
	valgrind $(LFLAGS)
	cat valgrind-out.txt
	
test:
	wget https://cdn.intra.42.fr/document/document/14455/checker_linux
	mv checker_linux checker
	chmod 777 checker

test3: $(NAME)
	$(eval ARG = $(shell shuf -i 0-50 -n 3))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test5: $(NAME)
	$(eval ARG = $(shell shuf -i 0-50 -n 5))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test100: $(NAME)
	$(eval ARG = $(shell shuf -i 0-1000 -n 100))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500: $(NAME)
	$(eval ARG = $(shell shuf -i 0-1000 -n 500))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re leaks test3 test5 test100