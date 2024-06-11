# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoyat <ngoyat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 20:04:59 by ngoyat            #+#    #+#              #
#    Updated: 2024/05/24 19:14:30 by ngoyat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server
FT_PRINTF = libftprintf.a
SRCC_FILES =	client.c
SRCS_FILES =	server.c
SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C ft_printf
		$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) ft_printf/$(FT_PRINTF) -o $(NAMEC)

$(NAMES) : $(OBJS)
		@make -C ft_printf
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) ft_printf/$(FT_PRINTF) -o $(NAMES)



clean :
		@make clean -C ft_printf
		${RM} ${OBJC}
		${RM} ${OBJS}

fclean : clean
		@make fclean -C ft_printf
		${RM} $(NAMEC)
		${RM} $(NAMES)
		${RM} $(FT_PRINTF)

re : fclean all

.PHONY:		all bonus clean fclean re
