# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 10:10:19 by caalbert          #+#    #+#              #
#    Updated: 2023/04/29 16:30:04 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
SRCS_DIR	= src
SRCS		= $(wildcard $(SRCS_DIR)/*.c)
OBJS_DIR	= obj
OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
CYAN			:= \033[1;36m
YELLOW			:= \033[1;33m
GREEN			:= \033[1;32m
RED				:= \033[1;31m
RESET			:= \033[0m
#                 # <-- start here         | <-- middle             # <-- stop here
HEADER_NAME 	= +                   * $(NAME) Compiled!                 #

all: 		$(NAME)

$(NAME): 	$(LIBFT) $(OBJS)
			@echo ""
			@echo "${YELLOW}\t * Compiling ${NAME}\n${CYAN}"
			ar -rcs $(NAME) $(OBJS)
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

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
			mkdir -p $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

norm:
	@echo "${GREEN}\n\n\t * Norminette start (-R Checcker)  * ${RESET}\n\n" ;
	@ norminette -R checker
	@echo "${GREEN}\n\n\t * Norminette ok! * ${RESET}\n\n" ;

push:
	@clear;
	@echo "\n\n${YELLOW}\t * Starting pushing - Feat(automatic) * ${RESET}" ;
	@echo "\033[1;36m \n" ;
	@git add . -v;
	@git status -b --l;
	@echo "\033[1;38m \n" ;
	@git commit -m "Feat(automatic): push all modification on file." -v;
	@echo "\033[1;36m \n" ;
	@git push -v;
	@echo "\n\n${GREEN}\t * Pushing complete * ${RESET}\n\n" ;

pull:
	@echo "\n\n\${YELLOW}\t * Starting Updated project * ${RESET}" ;
	@git pull --l
	@echo "${GREEN}\t * Project Updated  * ${RESET}\n\n" ;

.PHONY:		all clean fclean re norm push pull