require xorg-lib-common.inc
DESCRIPTION = "X11 Inter-Client Exchange library"
DEPENDS += "xproto${RE}-dev xtrans${RE}-dev"
PR = "${INC_PR}.0"

BBCLASSEXTEND = "native"
