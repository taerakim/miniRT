link_files:: unlink_files
	@mkdir -p $(dst_dir);
	$(foreach file,$(files), ln -sf $(src_dir)/$(file) $(dst_dir)/$(files);)

unlink_files::
	$(foreach file,$(files), $(RM) $(dst_dir)/$(files);)