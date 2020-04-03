SUBDIRS = src

dist_doc_DATA = README
EXTRA_DIST = share/intl/solo-oss-demo_zh_CN.po\
	pkgs

desktopdir = $(datadir)/applications
dist_desktop_DATA = assets/solo-oss-demo.desktop

iconsdir = $(datadir)/pixmaps

dist_icons_DATA = assets/solo-oss-demo.png

#if LINUX
#gtk_update_icon_cache = gtk-update-icon-cache -f -t $(iconsdir)

#install-data-hook: update-icon-cache
#uninstall-hook: update-icon-cache
#update-icon-cache:
#	@-if test -z "$(DESTDIR)"; then \
#		echo "Updating GTK icon cache."; \
#		$(gtk_update_icon_cache); \
#	else \
#		echo "*** Icon cache not updated. After (un)install, run this:"; \
#       	echo "*** $(gtk_update_icon_cache)"; \
#	fi
#endif 
