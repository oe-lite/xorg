require xorg-lib-common.inc
DESCRIPTION = "X11 keyboard UI presentation library"
LICENSE = "GPL"
DEPENDS += "libX11${RE}-dev libXt${RE}-dev libxkbfile${RE}-dev kbproto${RE}-dev  ${HOST_ARCH}/sysroot-libm"
PR = "${INC_PR}.0"
