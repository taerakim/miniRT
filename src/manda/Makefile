# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 13:14:14 by taerakim          #+#    #+#              #
#    Updated: 2024/06/16 04:21:13 by taerakim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
	TOPDIR = $(abspath ../../)
endif
ifndef SRCDIR
	SRCDIR = $(abspath ./)
endif

NAME := 
SRCS := .c \

# SRCS(in SRCDIR) ------
DIRS := \

SUBS := $(addsuffix .a,$(DIRS))

# LIBRARYS -------------
LDLIBS := -l

include $(TOPDIR)/include_make/Variable.mk
include $(TOPDIR)/include_make/Link.mk
include $(TOPDIR)/include_make/Recipe_subsrc.mk