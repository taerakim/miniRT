all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(SRCDIR) link_files
	$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(SRCDIR)/include link_files

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(SRCDIR) unlink_files
	$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(SRCDIR)/include unlink_files
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

norminette:
	norminette *.c
	norminette *.h

.PHONY: all clean fclean re norminette