HOMEPAGE = "http://www.x.org"
SECTION = "x11/utils"
LICENSE = "MIT-X"

SRC_URI = "${XORG_MIRROR}/individual/util/${P}.tar.bz2"

BBCLASSEXTEND = "native"

inherit autotools pkgconfig
