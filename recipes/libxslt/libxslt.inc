DESCRIPTION = "GNOME XSLT library"
SECTION = "libs"
PRIORITY = "optional"
LICENSE = "MIT"
INC_PR = "r0"

SRC_URI = "ftp://xmlsoft.org/libxml2/${BPN}-${PV}.tar.gz"

DEPENDS = "libxml2${RE}-dev \
${HOST_ARCH}/sysroot-libm ${HOST_ARCH}/sysroot-libdl \
"

BBCLASSEXTEND = "native"

inherit autotools pkgconfig binconfig

EXTRA_OECONF = "--without-python --without-debug --without-mem-debug --without-crypto"

FILES_${PN}-utils += "${bindir}"
FILES_${PN}-dev += "${bindir}/*-config ${libdir}/xsltConf.sh"
