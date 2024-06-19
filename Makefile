ifndef TOPDIR
	TOPDIR = $(abspath .)
endif

all bonus clean fclean re:
	$(MAKE) TOPDIR=`pwd` -C lib $@
	$(MAKE) TOPDIR=`pwd` -C src $@

norminette:
	$(MAKE) TOPDIR=`pwd` -C src $@

.PHONY: all clean fclean re bonus