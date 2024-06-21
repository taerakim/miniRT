ifndef TOPDIR
	TOPDIR = $(abspath ../../)
endif
ifndef SRCDIR
	SRCDIR = $(abspath ./)
endif

NAME := miniRT
SRCS := main.c \
		parse.c \
		parse_utils.c \
		init.c \
		convertor.c \
		mlx.c \
		ray.c \
		hit.c \

# SRCS(in SRCDIR) ------
DIRS := ft_error \
		vector \

#SUBS := $(addsuffix .a,$(DIRS))

# LIBRARYS -------------
LDLIBS := -lft -lmlx -framework OpenGL -framework Appkit

include $(TOPDIR)/include_make/Variable.mk
include $(TOPDIR)/include_make/Link.mk
include $(TOPDIR)/include_make/Recipe_src.mk