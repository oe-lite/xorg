require xorg-lib-common.inc

DESCRIPTION = "X Athena Widget Set"
DEPENDS += "xproto${RE}-dev libX11${RE}-dev libxext${RE}-dev xextproto${RE}-dev libXt${RE}-dev libxmu${RE}-dev libXpm${RE}-dev libxp${RE}-dev printproto${RE}-dev libxau${RE}-dev"
PR = "r0"

do_install_append () {
	ln -sf libXaw6.so.6 ${D}${libdir}/libXaw.so.6
	ln -sf libXaw7.so.7 ${D}${libdir}/libXaw.so.7
	ln -sf libXaw7.so.7 ${D}${libdir}/libXaw.so
}

PACKAGES =+ "libXaw6 libXaw7 libXaw8"

# disable docs as groff detection doesn't work on some hosts while cross compilling
EXTRA_OECONF += " --disable-docs "

FILES_libXaw6 = "${libdir}/libXaw*.so.6*"
FILES_libXaw7 = "${libdir}/libXaw*.so.7*"
FILES_libXaw8 = "${libdir}/libXaw8.so.8*"
