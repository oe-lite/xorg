SUMMARY = "Userspace interface to the kernel DRM services"
DESCRIPTION = "The runtime library for accessing the kernel DRM services.  DRM \
stands for \"Direct Rendering Manager\", which is the kernel portion of the \
\"Direct Rendering Infrastructure\" (DRI).  DRI is required for many hardware \
accelerated OpenGL drivers."
HOMEPAGE = "http://dri.freedesktop.org"

inherit autotools-autoreconf pkgconfig library

SRC_URI = "http://dri.freedesktop.org/libdrm/libdrm-${PV}.tar.bz2"

#libpciaccess is required starting from libdrm 2.4.26
DEPENDS = "libpthread-stubs libx11"

COMMON_DEPENDS += "librt libc libgcc libpciaccess"
DEPENDS += "${COMMON_DEPENDS}"
DEPENDS_${PN} += "${COMMON_DEPENDS}"
RDEPENDS_${PN} += "${COMMON_DEPENDS}"

PACKAGES =+ "${PN}-tests ${PN}-drivers ${PN}-kms"
FILES_${PN}-tests = "${bindir}/dr* ${bindir}/mode*"
FILES_${PN}-drivers = "${libdir}/libdrm_*.so.*"
FILES_${PN}-kms = "${libdir}/libkms*.so.*"


MIRRORS = """
http://mirrors.wayround.org/www.freedesktop.org/dri/dri.freedesktop.org/libdrm/ http://mirrors.wayround.org/www.freedesktop.org/dri/dri.freedesktop.org/libdrm/
"""
