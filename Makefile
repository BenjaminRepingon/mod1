# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/20 11:29:00 by rbenjami          #+#    #+#              #
#    Updated: 2015/01/24 16:35:49 by dsousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	g++

CFLAGS			=	-Wall -Werror -Wextra -ansi

NAME			=	mod1

SRCS			=	$(NAME).cpp			\
					Window.cpp			\
					Shader.cpp			\
					Utils.cpp			\
					Error.cpp			\
					Triangle.cpp		\
					Core.cpp			\
					AObject.cpp			\
					Vector3f.cpp		\
					Matrix4f.cpp		\
					Quaternion4f.cpp	\
					Vertex.cpp			\
					Map.cpp				\
					Transform.cpp		\
					Input.cpp			\
					WaterParticular.cpp	\
					Cube.cpp			\
					Sphere.cpp			\
					Camera.cpp

OBJS			=	$(SRCS:.cpp=.o)

INCLUDES		=	~/Library/Frameworks/SDL2.framework/Headers/

LIBS			=	-F ~/Library/Frameworks -framework SDL2 -framework OpenGL

all:			$(NAME)

$(NAME):		generate $(OBJS)
	@printf "Compiling objects"
	@$(CC) -o $(NAME) $(OBJS) $(LIBS)

generate:
	@printf "Generate objects: \n"

%.o:			%.cpp
	@$(CC) $(CFLAGS) -o $@ -c $< $(LIBS)
	@echo $@

clean:
	@printf "Remove objects\n"
	@rm -rf $(OBJS)

fclean:			clean
	@printf "Remove binary\n"
	@rm -rf $(NAME)

re:				fclean all


.PHONY: all, clean, fclean, re
