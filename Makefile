# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/20 11:29:00 by rbenjami          #+#    #+#              #
#    Updated: 2015/01/20 18:17:50 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	g++

CFLAGS			=	-Wall -Werror -Wextra -ansi

NAME			=	mod1

SRCS			=	$(NAME).cpp		\
					Window.cpp		\
					Shader.cpp		\
					Utils.cpp

OBJS			=	$(SRCS:.cpp=.o)

INCLUDES		=	~/Library/Frameworks/SDL2.framework/Headers/

LIBS			=	-F ~/Library/Frameworks -framework SDL2 -framework OpenGL

all:			$(NAME)

$(NAME):		$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBS)

%.o:			%.cpp
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES) $(LIBS)

clean:
	rm -rf $(OBJS)

fclean:			clean
	rm -rf $(NAME)

re:				fclean all


.PHONY: all, clean, fclean, re
