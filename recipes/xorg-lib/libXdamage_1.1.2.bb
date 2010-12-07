require xorg-lib-common.inc

DESCRIPTION = "X11 damaged region extension library"
LICENSE= "BSD-X"
DEPENDS += "damageproto${RE}-dev libXfixes${RE}-dev"
PR = "r1"
PE = "1"
