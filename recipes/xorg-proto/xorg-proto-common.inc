DESCRIPTION = "X protocol headers: ${BPN}"
HOMEPAGE = "http://www.x.org"
SECTION = "x11/libs"
LICENSE = "MIT-X"

DEPENDS = "util-macros-dev"
BBCLASSEXTEND = "native cross"
INC_PR = "r0"

require conf/mirror.conf
SRC_URI = "${XORG_MIRROR}/individual/proto/${BPN}-${PV}.tar.bz2"

inherit autotools pkgconfig
