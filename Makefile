# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carmeno <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 03:06:23 by carmeno           #+#    #+#              #
#    Updated: 2023/12/16 13:25:14 by deordone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deordone <deordone@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 11:18:16 by deordone          #+#    #+#              #
#    Updated: 2023/12/12 18:18:47 by deordone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCES = pipex.c ft_extractor.c

SRC_LIBFT = libft/libft.a

HEADER = include/pipex.h

OBJECTS = $(addprefix obj/, ${SOURCES:.c=.o})

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iinclude

MAKE_LIBFT = make -C libft

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: header make_lib $(NAME)

make_lib: 
	$(MAKE_LIBFT) 

$(NAME): compiled_libft $(OBJECTS) $(SRC_LIBFT)
		@printf "$(GREEN)";  
		$(CC) $(CFLAGS) $(OBJECTS) $(SRC_LIBFT) -o $(NAME)

obj/%.o: src/%.c $(HEADER) Makefile
		@printf "$(GREEN)";  
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

clean: ok
	rm -rf obj 
	$(MAKE_LIBFT) clean

fclean : ok clean
		rm -rf $(NAME)
		$(MAKE_LIBFT) fclean

re: fclean all 

# Definición de códigos de colores ANSI
RED=\033[0;31m
CYAN=\033[0;36m
GREEN=\033[0;32m
YELLOW=\033[0;33m
WHITE=\033[0;97m
BLUE=\033[0;34m
NC=\033[0m # No color

header: 
	@echo
	@printf "$(RED)		  ══════════════════════════「₪」══════════════════════════\n";
	@echo
	@printf "     	          $(YELLOW)                      ▒▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n";
	@printf "	     	                      ▒▒▒▒▒▒▒▒▒     ▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒\n";
	@printf "	     	                    ▒▒▒▒▒▒▒▒▒       ▒▒▒▒     ▒▒▒▒▒▒▒\n";
	@printf "	     	                  ▒▒▒▒▒▒▒▒▒         ▒▒      ▒▒▒▒▒▒▒\n";
	@printf "	     	                ▒▒▒▒▒▒▒▒▒                  ▒▒▒▒▒▒▒▒\n";
	@printf "	     	              ▒▒▒▒▒▒▒▒▒                  ▒▒▒▒▒▒▒▒\n";
	@printf "	     	            ▒▒▒▒▒▒▒▒                  ▒▒▒▒▒▒▒▒\n";
	@printf "	     	          ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒     ▒▒▒▒▒▒▒▒     ▒▒\n";
	@printf "	     	          ▒▒▒▒▒▒ Droied$(YELLOW) ▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒    ▒▒▒▒\n";
	@printf "	     	          ▒▒▒▒▒▒▒ Pacman ▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒\n";
	@printf "	     	          ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒   ▒▒ Barcelona ▒▒▒\n";
	@printf "	     	          ░░░░░ $(BLUE)  ░░░░░ $(YELLOW) ▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n";
	@printf "	     	         ░░░░$(WHITE)▀$(YELLOW)░░$(BLUE) ░$(WHITE)▄ $(BLUE)░$(WHITE)▄ $(BLUE)░ $(YELLOW)▒▒▒▒▒▒▒▒      |\n";
	@printf "	    	         ░░░░░  $(BLUE) ░░░░░░░$(YELLOW) ▒▒▒▒▒▒▒▒      ╰┈➤Pipex \n";
	@printf "	     	          ░░░░░ $(BLUE) ░ ░ ░ ░$(YELLOW) ▒▒▒▒▒▒▒▒$(NC)\n";
	@echo
	@printf "$(RED)		  ══════════════════════════「₪」══════════════════════════$(GREEN)\n";
	@echo
 
help: 
	@printf "\n";  
	@printf "	▂▃▅▆█▆▅▃▂ Commands ▂▃▅▆█▆▅▃▂\n";
	@printf "$(BLUE)		  ► help \n";
	@printf "		  ► clean \n";
	@printf "		  ► fclean \n";
	@printf "		  ► re \n";
	@printf "		  ► author $(NC)  \n";
	@printf "\n"; 
#	@tput setaf 009; echo "		  ► bonus "

author: 
	@printf "\n";
	@printf "$(CYAN)		       	       Created by Droied - Ataraxia\n";
	@printf "$(RED)		  ══════════════════════════「₪」══════════════════════════\n";
	@printf "$(CYAN)		        	https://github.com/Droied4 \n";

compiled_libft: 
	@echo
	@printf "$(RED)		  ══════════════════════════「LIBFT ₪ COMPILED」══════════════════════════\n";
	@echo

ok:
	@printf "\n"; 
	@printf "$(RED)Ok";
	@printf "\n"; 
.PHONY: all clean fclean re
