ifndef TOPDIR
	TOPDIR = $(abspath ../../)
endif
ifndef SRCDIR
	SRCDIR = $(abspath ./)
endif

NAME := miniRT_bonus
SRCS := main_bonus.c \
		init_bonus.c \
		mlx_bonus.c \

# SRCS(in SRCDIR) ------
DIRS := ft_error_bonus \
		vector_bonus \
		parse_bonus \
		render_bonus \

SUBS := $(addsuffix .a,$(DIRS))

# LIBRARYS -------------
LDLIBS := -lft -lmlx -framework OpenGL -framework Appkit

include $(TOPDIR)/include_make/Variable.mk
include $(TOPDIR)/include_make/Link.mk
include $(TOPDIR)/include_make/Recipe_src.mk