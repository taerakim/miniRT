ifndef TOPDIR
	TOPDIR = $(abspath ../)
endif

LIBS := libft \

all clean fclean re:
	$(foreach lib,$(LIBS),$(MAKE) TOPDIR=$(TOPDIR) -C $(lib) $@;)

bonus: all

.PHONY: all clean fclean re bonus