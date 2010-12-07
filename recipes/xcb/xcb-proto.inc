DESCRIPTION = "XCB: an X protocol C binding"
SECTION = "x11/libs"
LICENSE = "MIT-X"
HOMEPAGE = "http://xcb.freedesktop.org"

SRC_URI = "http://xcb.freedesktop.org/dist/${BPN}-${PV}.tar.bz2"

BBCLASSEXTEND = "native sdk"

inherit autotools pkgconfig binconfig

INC_PR = "r0"

prefix = "${prefix}/"
base_prefix="${base_prefix}/"
EXTRA_OECONF_append = "--prefix=${prefix}/ --exec_prefix=${exec_prefix}/"

BINCONFIG_GLOB += "${libdir}/pkgconfig/*.pc"

FILES_${PN}-dev += "${datadir}/xcb/*.xml ${datadir}/xcb/*.xsd ${libdir}/python*/dist-packages/ ${libdir}/python*/site-packages/"
ALLOW_EMPTY_${PN} = "1"
