DESCRIPTION = "PNG Library"
HOMEPAGE = "http://www.libpng.org/"
LICENSE = "libpng"
SECTION = "libs"
PRIORITY = "required"
DEPENDS = "zlib${RE}-dev"

INC_PR = "r0"

SRC_URI = "${SOURCEFORGE_MIRROR}/libpng/${BPN}-${PV}.tar.bz2;name=tarball"

inherit autotools pkgconfig binconfig

PACKAGES =+ "libpng3 libpng12"

FILES_libpng3 = "${libdir}/libpng.so.*"
FILES_libpng12 = "${libdir}/libpng12.so.*"
FILES_${PN}-dev = "${includedir} ${libdir}/lib*.so ${libdir}/*.la \
		${libdir}/*.a ${libdir}/pkgconfig \
		${datadir}/aclocal ${bindir} ${sbindir}"
