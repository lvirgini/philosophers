# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 20:46:01 by lvirgini          #+#    #+#              #
#    Updated: 2021/07/26 15:45:56 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ----------------- #
#	 VARIABLES		#
# ----------------- #

NAME =		philo

OBJ_DIR =	obj/
INC_DIR = 	$(shell find includes -type d)
SRC_DIR = 	$(shell find srcs -type d)

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)
vpath %.h $(foreach dir, $(INC_DIR)/, $(dir):)

SRC		= 	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
OBJ 	=	$(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

LIB		= pthread

# ----------------- #
#	 COMPILATION	#
# ----------------- #

CC = 			gcc
CFLAG =			-Wall -Werror -Wextra
CFLAG_LEAK = 	$(CFLAG) -fsanitize=leak
CFLAG_ADDRESS = $(CFLAG) -fsanitize=address
CFLAG_THREAD = 	$(CFLAG) -fsanitize=thread 
IFLAG = 		$(foreach dir, $(INC_DIR), -I $(dir))
LFLAG =			$(foreach lib, $(LIB), -l $(lib) )
 

# ----------------- #
#	  FONCTIONS		#
# ----------------- #

$(OBJ_DIR)%.o: %.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@echo "\033[32mCompilation de ... $(foreach file, $< , $(notdir $<))\033[0m"
			@$(CC) $(CFLAG) $(IFLAG) -o $@ -c $<
			
$(NAME):	$(OBJ) $(INC_DIR)
			$(CC) $(CFLAG) $(IFLAG) $(OBJ) -o $@ $(LFLAG)
			@echo "\n\t\033[36;1m*.............................*"
			@echo "\n\t*     Compilation $(NAME)     *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
			@echo "\n\t\033[036;1m*.............................*\033[0m"
	
all:		${NAME}

debug :		$(OBJ) $(INC_DIR)
			@$(CC) $(CFLAG) $(IFLAG) $(OBJ)

leak : 		$(OBJ) $(INC_DIR)
			$(CC) $(CFLAG_LEAK) $(IFLAG) $(OBJ) -o $(NAME) $(LFLAG)

thread :	$(OBJ) $(INC_DIR)
			$(CC) $(CFLAG_THREAD) $(IFLAG) $(OBJ) -o $(NAME) $(LFLAG)

adress :	$(OBJ) $(INC_DIR)
			$(CC) $(CFLAG_ADDRESS) $(IFLAG) $(OBJ) -o $(NAME) $(LFLAG)

show	:
			@echo "SRC_DIR : $(SRC_DIR)\n"
			@echo "LIB_DIR : $(LIB_DIR)\n"
			@echo "INC_DIR : $(INC_DIR)\n"
			@echo "CFLAG : $(CFLAG)\n"
			@echo "IFLAG : $(IFLAG)\n"
			@echo "LFLAG : $(LFLAG)\n"
			@echo "HEADERS : $(foreach file, $(HEADERS),\n\t$(file))\n"
			@echo "SRC :$(foreach file, $(SRC),\n\t$(file))\n"
			@echo "OBJ :$(foreach file, $(OBJ),\n\t$(file))\n"


# ----------------- #
# 		CLEAN		#
# ----------------- #

clean:
			@rm -rf $(OBJ_DIR)
			@echo "\033[36;1m ------>>  clean\033[0m"

fclean:		clean
			@rm -f $(NAME) a.out
			@echo "\033[36;1m ------>> fclean\033[0m"

re:			fclean all

.PHONY: 	all clean fclean re