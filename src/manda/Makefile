ifndef TOPDIR
	TOPDIR = $(abspath ../../)
endif
ifndef SRCDIR
	SRCDIR = $(abspath ./)
endif

NAME := miniRT
SRCS := main.c \
		init.c \
		mlx.c \
		render.c \
		ray.c \
		hit.c \
		split.c \
		split_utils.c \

# SRCS(in SRCDIR) ------
DIRS := ft_error \
		parse \
		vector \

SUBS := $(addsuffix .a,$(DIRS))

# LIBRARYS -------------
LDLIBS := -lft -lmlx -framework OpenGL -framework Appkit

include $(TOPDIR)/include_make/Variable.mk
include $(TOPDIR)/include_make/Link.mk
include $(TOPDIR)/include_make/Recipe_src.mk