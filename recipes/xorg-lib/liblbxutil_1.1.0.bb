require xorg-lib-common.inc

DESCRIPTION = "XFIXES Extension"
DEPENDS += "xextproto${RE}-dev xproto${RE}-dev zlib${RE}-dev"
PROVIDES_${PN} = "lbxutil lbxutil-dev"

SRC_URI += "file://mkg3states-1.1.patch;patch=1"

AUTOTOOLS_AUTORECONF = "Do what's right. Do it right. Do it right now"
acpaths = "-I ${MACHINE_SYSROOT}${datadir}/aclocal"

export CC_FOR_BUILD = "${BUILD_CC}"
