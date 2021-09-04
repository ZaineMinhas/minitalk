# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/30 16:50:02 by zminhas           #+#    #+#              #
#    Updated: 2021/09/04 15:38:33 by zminhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		= $(shell tput -Txterm setaf 0)
RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)

SRCS_SERVER	=	main_server.c\

SRCS_CLIENT	=	\


OBJS_SERVER	=	${SRCS_SERVER:.c=.o}

OBJS_CLIENT	=	${SRCS_CLIENT:.c=.o}

EXEC_1	=	server

EXEC_2	=	client

LIB_PATH	=	./libft

.c.o:
		@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}

all:	${OBJS_SERVER}
		@make -C ${LIB_PATH}
		@gcc -Wall -Wextra -Werror main_server.c $(LIB_PATH)/libft.a -o $(EXEC_1)
		@echo "${GREEN}server created !${RESET}"

server:	${OBJS_SERVER}
		@make -C ${LIB_PATH}
		@gcc -Wall -Wextra -Werror main_server.c $(LIB_PATH)/libft.a -o $(EXEC_1)
		@echo "${GREEN}server created !${RESET}"

client:	${OBJS}
		@make -C ${LIB_PATH}
		@gcc -Wall -Wextra -Werror main_client.c $(LIB_PATH)/libft.a -o $(EXEC_2)
		@echo "${GREEN}client created !${RESET}"

sc:		server client

clean:
		@rm -f ${OBJS_SERVER}
		@rm -f ${OBJS_CLIENT}
		@make clean -C ${LIB_PATH}
		@echo "${YELLOW}Objects cleaned !${RESET}"

fclean:
		@rm -f ${OBJS_SERVER}
		@rm -f ${OBJS_CLIENT}
		@rm -f $(EXEC_1)
		@rm -f $(EXEC_2)
		@make fclean -C ${LIB_PATH}
		@echo "${RED}fclean done !${RESET}"

re:			fclean all

.PHONY:		all clean fclean re server client