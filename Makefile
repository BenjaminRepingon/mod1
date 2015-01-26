# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/20 11:29:00 by rbenjami          #+#    #+#              #
#    Updated: 2015/01/26 13:58:10 by rbenjami         ###   ########.fr        #
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
					Mesh.cpp			\
					Core.cpp			\
					AObject.cpp			\
					BasicObject.cpp		\
					Vector2f.cpp		\
					Vertex.cpp			\
					Input.cpp			\
					Transform.cpp		\
					Camera.cpp
					# Map.cpp				\
					# Vector3f.cpp		\
					# Matrix4f.cpp		\
					# Quaternion4f.cpp	\

OBJS			=	$(SRCS:.cpp=.o)

ifeq ($(shell uname), Linux)
	LIBS		=	-lglut -lGL -lGLU -lSDL2 -I/usr/include/GLES2/ -I./glfw-3.1/include/GLFW/
else
	LIBS		=	-F ~/Library/Frameworks -framework SDL2 -framework OpenGL
	LIBS		+=	-L ~/.brew/Cellar/glfw3/3.0.4/lib -lglfw3 -I ~/.brew/Cellar/glfw3/3.0.4/include
endif

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
