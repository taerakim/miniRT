# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:03:24 by taerakim          #+#    #+#              #
#    Updated: 2024/02/18 14:00:05 by taerakim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ../)
endif

MANDATORY = manda
BONUS = bonus

clean fclean norminette:
	$(MAKE) TOPDIR=$(TOPDIR) -C $(MANDATORY) $@
	$(MAKE) TOPDIR=$(TOPDIR) -C $(BONUS) $@

all re:
	$(MAKE) TOPDIR=$(TOPDIR) -C $(MANDATORY) $@

bonus:
	$(MAKE) TOPDIR=$(TOPDIR) -C $(BONUS) all

.PHONY: all clean fclean re bonus