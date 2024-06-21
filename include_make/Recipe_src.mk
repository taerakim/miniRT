all:
	$(foreach dir,$(DIRS),$(MAKE) TOPDIR=$(TOPDIR) SRCDIR=`pwd` -C $(dir) $@;)
	$(MAKE) $(NAME)

$(NAME): $(OBJS) $(SUBS)
	$(LINK.o) $^ $(LDLIBS) -o $@
	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR) link_files

clean:
	$(foreach dir,$(DIRS),$(MAKE) TOPDIR=$(TOPDIR) SRCDIR=`pwd` -C $(dir) $@;)
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(foreach dir,$(DIRS),$(MAKE) TOPDIR=$(TOPDIR) SRCDIR=`pwd` -C $(dir) $@;)
	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR) unlink_files
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

norminette:
	norminette *.c
	norminette *.h
	$(foreach dir,$(DIRS),$(MAKE) TOPDIR=$(TOPDIR) SRCDIR=`pwd` -C $(dir) $@;)

.PHONY: all clean fclean re norminette