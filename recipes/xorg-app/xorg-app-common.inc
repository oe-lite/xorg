DESCRIPTION ?= "X application"
HOMEPAGE ?= "http://www.x.org/"

LICENSE ?= "MIT-X"
DEPENDS = "cross:util-macros libx11 xproto"
RDEPENDS_${PN} = "libx11"

XORG_MIRROR = "http://xorg.freedesktop.org/releases"
SRC_URI = "${XORG_MIRROR}/individual/app/${PN}-${PV}.tar.bz2"

S = "${SRCDIR}/${PN}-${PV}"

inherit autotools pkgconfig c++

FILES_${PN} += "  /usr/lib/X11/${PN} /usr/share/X11/app-defaults/"

DEPENDS_${PN}[qa] = "allow-missing-lib-depends"