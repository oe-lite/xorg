HOMEPAGE = "http://www.x.org"
SECTION = "x11/libs"
LICENSE = "MIT-X"
DEPENDS = "util-macros${RE}-dev xorg-headers-native${RE}-dev xproto${RE}-dev"

INC_PR = "r0"
require conf/mirror.conf
SRC_URI = "${XORG_MIRROR}/individual/lib/${BPN}-${PV}.tar.bz2"

inherit autotools pkgconfig

EXTRA_OECONF = "--enable-malloc0returnsnull"
