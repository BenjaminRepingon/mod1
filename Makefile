# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 12:57:14 by rbenjami          #+#    #+#              #
#    Updated: 2015/03/09 12:06:21 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:

clean:
	@rm -Rf ./.params.js

fclean:			clean

re:				fclean all

.PHONY: all, clean, fclean, re
