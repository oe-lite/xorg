require xorg-lib-common.inc
DESCRIPTION = "X11 font encoding library"
LICENSE = "BSD-X"
DEPENDS += "zlib${RE}-dev xproto${RE}-dev font-util-native"
PR = "${INC_PR}.0"
DEFAULT_PREFERENCE = "-1"
BBCLASSEXTEND = "native"
