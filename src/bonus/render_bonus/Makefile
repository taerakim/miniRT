ifndef TOPDIR
	TOPDIR = $(abspath ../../../)
endif
ifndef SRCDIR
	SRCDIR = $(abspath ../)
endif

NAME := render_bonus.a
SRCS := render_bonus.c \
		ray_bonus.c \
		hit_bonus.c \
		hit_cylinder_bonus.c \
		hit_cone_bonus.c \
		hit_trace_bonus.c \
		calc_bonus.c \
		lighting_bonus.c \
		color_bonus.c \

include $(TOPDIR)/include_make/Variable.mk
include $(TOPDIR)/include_make/Link.mk
include $(TOPDIR)/include_make/Recipe_subsrc.mk