require xorg-lib-common.inc
DESCRIPTION = "X11 keyboard file manipulation library"
LICENSE = "GPL"
DEPENDS += "libX11${RE}-dev kbproto${RE}-dev"
PE = "1"
PR = "${INC_PR}.0"
BBCLASSEXTEND = "native"
