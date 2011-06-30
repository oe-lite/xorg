DESCRIPTION = "GNOME XSLT library"
PRIORITY = "optional"
LICENSE = "MIT"

SRC_URI = "ftp://xmlsoft.org/libxml2/libxslt-${PV}.tar.gz"

DEPENDS = "libxml2-dev \
		   ${TARGET_ARCH}/sysroot-libm \
		   ${TARGET_ARCH}/sysroot-libpthread \
           ${TARGET_ARCH}/sysroot-libdl"
DEPENDS_recipe-native = "libxml2-native-dev"

BBCLASSEXTEND = "native"

inherit autotools

EXTRA_OECONF = "--without-python --without-debug --without-mem-debug --without-crypto"

FILES_${PN}-utils += "${bindir}"
FILES_${PN}-dev += "${bindir}/*-config ${libdir}/xsltConf.sh"
