SUMMARY = "Xlib: C Language X Interface library"

DESCRIPTION = "This package provides a client interface to the X Window \
System, otherwise known as 'Xlib'.  It provides a complete API for the \
basic functions of the window system."

require xorg-lib-common.inc

# reconf packaged configure uses pkg-config --variable to get
# includepath for keysyms.h. Result: No PKGCONFIG_SYSROOT prefix.
inherit siteinfo autotools-autoreconf


XORG_PN = "libX11"
LICENSE = "MIT & MIT-style & BSD"

DEPENDS += "util-macros"

EXTRA_OECONF += "--with-groff=no --with-ps2pdf=no --with-fop=no --disable-specs"
AUTORECONF_CMD = " \
   ${LIBTOOLIZE} --force --automake --copy \
&& aclocal $acpaths --force \
&& autoconf $acpaths --force \
&& automake -a --copy --force; \
"

PACKAGES =+ "${PN}-xcb"

PROVIDES_${PN}-xcb = "libX11-xcb"

DEPENDS_${PN} += "kbproto libc"
RDEPENDS_${PN} += "libxcb libxau libxdmcp"

DEPENDS_${PN}-xcb += "${PN}"
RDEPENDS_${PN}-xcb += "${PN}"

FILES_${PN} += "${datadir}/X11/XKeysymDB ${datadir}/X11/XErrorDB ${libdir}/X11/Xcms.txt"
FILES_${PN}-xcb += "${libdir}/libX11-xcb.so.*"
FILES_${PN}-locale += "${datadir}/X11/locale ${libdir}/X11/locale"




