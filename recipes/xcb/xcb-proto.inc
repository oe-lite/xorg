SUMMARY = "XCB: The X protocol C binding headers"
DESCRIPTION = "Function prototypes for the X protocol C-language Binding \
(XCB).  XCB is a replacement for Xlib featuring a small footprint, \
latency hiding, direct access to the protocol, improved threading \
support, and extensibility."
HOMEPAGE = "http://xcb.freedesktop.org"
BUGTRACKER = "https://bugs.freedesktop.org/enter_bug.cgi?product=XCB"

LICENSE = "MIT-X"

RECIPE_TYPES = "native sdk machine"
SRC_URI = "http://xcb.freedesktop.org/dist/xcb-proto-${PV}.tar.bz2"

DEPENDS_${PN}           = "${PN}-dev_${PV}"
DEPENDS_${PN}-dev       = ""

inherit autotools pkgconfig

FILES_${PN}-dev += "${datadir}/xcb/*.xml ${datadir}/xcb/*.xsd"

RDEPENDS_${PN}-dev = ""

PACKAGES += "python-xcbgen"
FILES_python-xcbgen = "${libdir}/python*"

#RRECOMMENDS_${PN}-dbg = "${PN}-dev (= ${EXTENDPKGV})"

#DEPENDS:native += " python-native"

EXTRA_OECONF += "--prefix=${prefix}/"

