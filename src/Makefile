ifndef TOPDIR
	TOPDIR = $(abspath ../)
endif

MANDATORY = manda
BONUS = bonus

clean fclean norminette:
	$(MAKE) TOPDIR=$(TOPDIR) -C $(MANDATORY) $@
	$(MAKE) TOPDIR=$(TOPDIR) -C $(BONUS) $@

all re:
	$(MAKE) TOPDIR=$(TOPDIR) -C $(MANDATORY) $@

bonus:
	$(MAKE) TOPDIR=$(TOPDIR) -C $(BONUS) all

.PHONY: all clean fclean re bonus