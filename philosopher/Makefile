# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 20:46:01 by lvirgini          #+#    #+#              #
#    Updated: 2021/09/06 10:03:37 by lvirgini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ----------------- #
#	 VARIABLES		#
# ----------------- #

NAME =		philo

OBJ_DIR =	obj/
INC_DIR = 	includes/
SRC_DIR = 	srcs srcs/errors srcs/init_struct srcs/parser srcs/routine srcs/time srcs/utils

OBJ		= $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

LIB		=	pthread

SRCS	=	main.c \
			error.c\
			thread_init.c \
			init_fork.c \
			init_philo.c \
			init_rules.c \
			init_table.c \
			parse_args.c\
			checker_routine.c \
			eating_routine.c \
			global_routine.c \
			print_status.c\
			get_time.c \
			ms_sleep.c \
			second_convertor.c\
			ft_isspace_isdigit.c \
			ft_itoa_ltoa.c \
			ft_memset.c \
			ft_putstr.c \
			ft_strncpy.c \
			mini_atoi.c

vpath %.c $(foreach dir, $(SRC_DIR)/, $(dir):)
vpath %.h $(foreach dir, $(INC_DIR), $(dir):)

# ----------------- #
#	 COMPILATION	#
# ----------------- #

CC = 			gcc
CFLAG =			-Wall -Werror -Wextra
IFLAG = 		$(foreach dir, $(INC_DIR), -I $(dir))
LFLAG =			$(foreach lib, $(LIB), -l $(lib) )

# ----------------- #
#	  FONCTIONS		#
# ----------------- #


$(OBJ_DIR):
			@mkdir -p $@


$(OBJ_DIR)%.o: %.c $(HEADERS) | $(OBJ_DIR)
			@echo "\033[32mCompilation de ... $(foreach file, $< , $(notdir $<))\033[0m"
			@$(CC) $(CFLAG) $(IFLAG) -o $@ -c $<
			
$(NAME)	:	$(OBJ) $(INC_DIR)
			@$(CC) $(CFLAG) $(IFLAG) $(OBJ) -o $@ $(LFLAG)
			@echo "\n\t\033[36;1m*.............................*"
			@echo "\n\t*     Compilation $(NAME)       *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
			@echo "\n\t\033[036;1m*.............................*\033[0m\n"
	
all		:	${NAME}

show	:
			@echo "SRC_DIR : $(SRC_DIR)\n"
			@echo "LIB_DIR : $(LIB_DIR)\n"
			@echo "INC_DIR : $(INC_DIR)\n"
			@echo "CFLAG : $(CFLAG)\n"
			@echo "IFLAG : $(IFLAG)\n"
			@echo "LFLAG : $(LFLAG)\n"
			@echo "HEADERS : $(foreach file, $(HEADERS),\n\t$(file))\n"
			@echo "SRC : $(foreach file, $(SRCS),\n\t$(file))\n"
			@echo "OBJ : $(foreach file, $(OBJ),\n\t$(file))\n"


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