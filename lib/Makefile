# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 16:34:15 by taerakim          #+#    #+#              #
#    Updated: 2024/02/20 21:32:15 by taerakim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ../)
endif

LIBS := libsub \

all clean fclean re:
	$(foreach lib,$(LIBS),$(MAKE) TOPDIR=$(TOPDIR) -C $(lib) $@;)

bonus: all

.PHONY: all clean fclean re bonus