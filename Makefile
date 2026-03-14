OBJ_DIR ?= ./obj
SRC_DIR = ./src
HDR_DIR = ./header

SRC = main.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = philo

all : $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -pthread -c $< -o $@

$(NAME): make_msg $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)

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
