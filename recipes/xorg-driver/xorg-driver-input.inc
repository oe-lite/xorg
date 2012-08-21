include xorg-driver-common.inc

DEPENDS += "inputproto kbproto pixman xextproto libpciaccess"

FILES_${PN} += " ${libdir}/xorg/modules/input/*.so"
FILES_${PN}-dbg += " ${libdir}/xorg/modules/input/.debug"
