ifndef TOPDIR
	TOPDIR = $(abspath ../../)
endif
ifndef SRCDIR
	SRCDIR = $(abspath ./)
endif

NAME := miniRT
SRCS := parse.c \
		parse_utils.c \
		convertor.c \

## SRCS(in SRCDIR) ------
#DIRS := \

#SUBS := $(addsuffix .a,$(DIRS))

# LIBRARYS -------------
LDLIBS := -lft

include $(TOPDIR)/include_make/Variable.mk
include $(TOPDIR)/include_make/Link.mk
include $(TOPDIR)/include_make/Recipe_src.mk