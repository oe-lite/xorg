require xorg-lib-common.inc
DESCRIPTION = "X11 font rasterisation library"
LICENSE = "BSD-X"
DEPENDS += "zlib${RE}-dev freetype${RE}-dev freetype-native-dev fontcacheproto${RE}-dev xtrans${RE}-dev fontsproto${RE}-dev libfontenc${RE}-dev ${HOST_ARCH}/sysroot-libm"
PR = "${INC_PR}.0"

# disable docs
EXTRA_OECONF += " --disable-devel-docs "

BBCLASSEXTEND = "native"
