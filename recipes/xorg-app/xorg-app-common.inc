DESCRIPTION = "X application"
HOMEPAGE = "http://www.x.org/"
SECTION = "x11/apps"
LICENSE = "MIT-X"
DEPENDS = "util-macros-native libX11${RE}-dev"

SRC_URI = "${XORG_MIRROR}/individual/app/${BPN}-${PV}.tar.bz2;name=archive"

inherit autotools pkgconfig

FILES_${PN} += "  /usr/lib/X11/${BPN}"
BBCLASSEXTEND = "native"