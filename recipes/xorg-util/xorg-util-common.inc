HOMEPAGE = "http://www.x.org"
BUGTRACKER = "https://bugs.freedesktop.org/enter_bug.cgi?product=xorg"

LICENSE = "MIT-X"

require conf/fetch/xorg.conf

XORG_PN = "${PN}"
SRC_URI = "${XORG_MIRROR}/individual/util/${XORG_PN}-${PV}.tar.gz"

S = "${SRCDIR}/${XORG_PN}-${PV}"

inherit autotools-autoreconf pkgconfig
