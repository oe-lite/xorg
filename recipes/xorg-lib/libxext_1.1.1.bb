require xorg-lib-common.inc

DESCRIPTION = "X11 miscellaneous extension library"
DEPENDS += "xproto${RE}-dev libX11${RE}-dev xextproto libxau"
PROVIDES = "xext"
PR = "r1"
XORG_PN = "libXext"
