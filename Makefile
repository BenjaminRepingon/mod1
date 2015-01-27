# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 12:57:14 by rbenjami          #+#    #+#              #
#    Updated: 2015/01/27 17:23:34 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	./res/compressjs.sh src/*.js ./res/mod1.min.js

clean:
	@echo "Remove mod1.min.js"
	@rm -Rf ./res/mod1.min.js
	@rm -Rf ./.map

fclean:			clean

re:				fclean all

.PHONY: all, clean, fclean, re
