DESCRIPTION = "userspace library for accessing the DRM(direct rendering manager)"
HOMEPAGE = "http://dri.freedesktop.org"
SECTION = "x11/base"
LICENSE = "MIT"
SRC_URI = "http://dri.freedesktop.org/libdrm/libdrm-${PV}.tar.bz2"
DEPENDS = "libpthread-stubs${RE}-dev  cairo${RE}-dev libX11${RE}-dev"
#udev

inherit autotools pkgconfig

PACKAGES =+ "libdrm-tests"
FILES_libdrm-tests = "${bindir}/dr* ${bindir}/mode*"

LEAD_SONAME = "libdrm.so"
