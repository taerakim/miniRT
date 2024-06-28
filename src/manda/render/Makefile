ifndef TOPDIR
	TOPDIR = $(abspath ../../../)
endif
ifndef SRCDIR
	SRCDIR = $(abspath ../)
endif

NAME := render.a
SRCS := render.c \
		ray.c \
		hit.c \
		hit_cylinder.c \
		hit_cone.c \
		hit_trace.c \
		calc.c \
		lighting.c \
		color.c \

include $(TOPDIR)/include_make/Variable.mk
include $(TOPDIR)/include_make/Link.mk
include $(TOPDIR)/include_make/Recipe_subsrc.mk