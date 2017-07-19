# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/06 04:01:59 by sbonnefo          #+#    #+#              #
#    Updated: 2017/07/19 02:36:56 by sbonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC_PATH = ./srcs
OBJ_PATH = ./obj
LIB_PATH = ./libft

SRC =	$(addprefix $(SRC_PATH)/, main.c \
		cd_errors.c \
		cd_start.c \
		cd_step1.c \
		cd_step5.c \
		cd_step6.c \
		cd_step7.c \
		cd_step8.c \
		cd_step9.c \
		cd_step10.c \
		ft_getenv.c \
		ft_setenv.c \
		ft_freetab.c \
		prompt.c \
		echo.c \
		exec.c \
		signals.c \
		errors.c \
		ft_env.c \
		ft_jointab.c \
		ft_unsetenv.c)

OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

INCLUDES = ./includes ./libft

LIB = $(LIB_PATH)/libft.a

FLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIB) $(OBJ) $(LIB_MLX) Makefile
	@gcc $(FLAGS) -o $(NAME) $(LIB) $(OBJ)
	@echo "$(NAME) \033[30;42mmade\033[0m"

$(LIB_MLX):
	@make -C $(MLX_PATH)

fclean: clean
	@rm -Rf $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo "$(NAME) \t\033[30;42m Delete\033[0m\033[0m (make $@ done for $(NAME))"

debug:
	@gcc -g $(FLAGS) $(MLX_INC) -o $(NAME) $(LIB) $(LIB_MLX) $(OBJ)

$(LIB):
	@make -C $(LIB_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDES)
	@gcc $(FLAGS) -o $@ -c $< $(addprefix -I , $(INCLUDES))

norm:
	norminette libft $(INCLUDES)
	norminette $(SRC)

clean:
	@rm -Rf $(OBJ)
	@make clean -C $(LIB_PATH)

re: fclean all
