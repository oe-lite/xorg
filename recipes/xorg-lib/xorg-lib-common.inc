LICENSE = "MIT-X"
DEPENDS = "util-macros"

require conf/fetch/xorg.conf

XORG_PN ?= "${PN}"
SRC_URI = "${XORG_MIRROR}/individual/lib/${XORG_PN}-${PV}.tar.bz2"

DEPENDS_${PN}           = "${PN}-dev_${PV}"
DEPENDS_${PN}-dev       = ""

S = "${SRCDIR}/${XORG_PN}-${PV}"

inherit autotools pkgconfig library
PROVIDES_${PN} += "${XORG_PN}"

EXTRA_OECONF = "--enable-malloc0returnsnull --with-fop=no --without-xmlto"

