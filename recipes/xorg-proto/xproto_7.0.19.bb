require xorg-proto-common.inc
inherit binconfig
BINCONFIG_GLOB += "${libdir}/pkgconfig/*.pc"
PR = "${INC_PR}.0"
