DESCRIPTION = "X protocol headers: ${XORG_PN}"

require conf/fetch/xorg.conf

LICENSE = "MIT-X"

XORG_PN = "${PN}"

SRC_URI = "${XORG_MIRROR}/individual/proto/${XORG_PN}-${PV}.tar.bz2"

S = "${SRCDIR}/${XORG_PN}-${PV}"

DEPENDS = "util-macros"
DEPENDS_${PN}           = "${PN}-dev_${PV}"
DEPENDS_${PN}-dev       = ""

inherit autotools pkgconfig

EXTRA_OECONF = "--with-fop=no --without-xmlto"

# ${PN} is empty so we need to tweak -dev and -dbg package dependencies
RDEPENDS_${PN}-dev = ""
