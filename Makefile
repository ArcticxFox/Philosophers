# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/19 14:40:08 by ejones            #+#    #+#              #
#    Updated: 2026/03/19 14:41:46 by ejones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR ?= ./obj
SRC_DIR = ./src
HDR_DIR = ./header

SRC = main.c thread_management.c parsing.c get_elapsed_time.c utils.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = philo

NUM_SRC := $(words $(SRC))
COUNT := 0
BAR_WIDTH := 50

all: make_msg $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -pthread -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo "\e[32m\n===================== FINISHED ======================\n\e[0m"

clean: cln_msg
	@rm -rf $(OBJ_DIR)
fclean: clean
	@echo "\e[33m	- deleting executables\e[0m"
	@rm -f $(NAME)
re: re_msg fclean all

re_msg:
	@echo "\e[31m\n================= Re-making Project =================\e[0m"
make_msg:
	@echo "\e[32m\n================== Making Project ===================\n\e[0m"
cln_msg:
	@echo "\e[33m\n================= Removing ./objects ================\n\e[0m"

.PHONY: all clean fclean re
