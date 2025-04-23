# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouryal <ybouryal@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 10:34:10 by ybouryal          #+#    #+#              #
#    Updated: 2025/02/27 13:41:38 by ybouryal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREEN		:= $(shell tput -Txterm setaf 2)
BOLD		:= $(shell tput bold);
RESET		:= $(shell tput -Txterm sgr0)

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I$(HEAD) -g
LDFLAGS		= -lpthread
RM			= rm -rf

SRCS_DIR	= src
OBJS_DIR	= obj
HEAD		= inc

FILES		= actions.c cleanup.c main.c parser.c routines.c \
			  simulation.c utils_1.c utils_2.c
SRCS		= $(addprefix $(SRCS_DIR)/, $(FILES))
OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

NAME		= philo

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(OBJS) -o $@ $(LDFLAGS)
			@echo "$(BOLD)$(GREEN)$(NAME) compiled Successfully$(RESET)"

$(OBJS_DIR)/%.o:		$(SRCS_DIR)/%.c
			@mkdir -p $(OBJS_DIR)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "Compiling $(NAME) ..."

clean:
			@$(RM) $(OBJS_DIR)
			@echo "Cleaning obj files."

fclean:	
			@echo "Cleaning all files."
			@$(MAKE) clean
			@$(RM) $(NAME)

re:
			@echo "Rebuild $(NAME)"
			@$(MAKE) fclean
			@$(MAKE) all

test: $(NAME)
	@cd ./test && bash ./test.sh

.PHONY: all clean fclean re test
.SECONDARY:	$(OBJS)
