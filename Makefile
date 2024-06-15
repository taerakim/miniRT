# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 13:55:28 by taerakim          #+#    #+#              #
#    Updated: 2024/02/18 14:08:19 by taerakim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath .)
endif

all bonus clean fclean re:
	$(MAKE) TOPDIR=`pwd` -C lib $@
	$(MAKE) TOPDIR=`pwd` -C src $@

norminette:
	$(MAKE) TOPDIR=`pwd` -C src $@

.PHONY: all clean fclean re bonus