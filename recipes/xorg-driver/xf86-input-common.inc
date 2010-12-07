include xorg-driver-common.inc

DEPENDS += "inputproto${RE}-dev xextproto${RE}-dev  kbproto${RE}-dev"

FILES_${PN} += " ${libdir}/xorg/modules/input/*.so"
FILES_${PN}-dbg += " ${libdir}/xorg/modules/input/.debug"
