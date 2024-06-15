all bonus: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR)/lib link_files
	$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/include link_files

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR)/lib unlink_files
	$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/include unlink_files

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re