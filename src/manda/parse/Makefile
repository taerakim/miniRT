ifndef TOPDIR
	TOPDIR = $(abspath ../../../)
endif
ifndef SRCDIR
	SRCDIR = $(abspath ../)
endif

NAME := parse.a
HEAD := parse.h
SRCS := parse.c \
		convertor.c \
		constructor.c \
		constructor2.c \
		parse_utils.c \
		split.c \
		split_utils.c \
		validate.c \

include $(TOPDIR)/include_make/Variable.mk
include $(TOPDIR)/include_make/Link.mk
include $(TOPDIR)/include_make/Recipe_subsrc.mk