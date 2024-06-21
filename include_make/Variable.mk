.DELETE_ON_ERROR:
.DEFAULT_GOAL = all

CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs
CPPFLAGS = -I$(TOPDIR)/include -I$(SRCDIR)/include
LDFLAGS = -L$(TOPDIR)/lib

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

ifdef DEPS
	CPPFLAGS += -MMD -MP
endif
ifdef DEBUG
	CPPFLAGS += -g
endif