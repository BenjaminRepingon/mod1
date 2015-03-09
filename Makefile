# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 12:57:14 by rbenjami          #+#    #+#              #
#    Updated: 2015/03/09 14:05:58 by dsousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=.params.js

all: $(NAME)

$(NAME):
	@touch $(NAME)

clean:
	@rm -Rf ./.params.js

fclean:			clean

re:				fclean all

.PHONY: all, clean, fclean, re
