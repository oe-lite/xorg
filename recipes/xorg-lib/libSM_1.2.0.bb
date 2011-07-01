require xorg-lib-common.inc
DESCRIPTION = "X11 Session management library"
DEPENDS += "libICE${RE}-dev xproto${RE}-dev xtrans${RE}-dev util-linux${RE}-dev"
PR = "${INC_PR}.0"

BBCLASSEXTEND = "native"
