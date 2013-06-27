include xorg-driver-common.inc

DEPENDS += "inputproto kbproto pixman xextproto libpciaccess"
DEPENDS += "renderproto fontsproto videoproto"

FILES_${PN} += " ${libdir}/xorg/modules/input/*.so"
FILES_${PN}-dbg += " ${libdir}/xorg/modules/input/.debug"
