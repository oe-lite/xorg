SUMMARY = "Userspace interface to the kernel DRM services"
DESCRIPTION = "The runtime library for accessing the kernel DRM services.  DRM \
stands for \"Direct Rendering Manager\", which is the kernel portion of the \
\"Direct Rendering Infrastructure\" (DRI).  DRI is required for many hardware \
accelerated OpenGL drivers."
HOMEPAGE = "http://dri.freedesktop.org"

inherit autotools-autoreconf pkgconfig library

SRC_URI = "https://dri.freedesktop.org/libdrm/libdrm-${PV}.tar.bz2"

#libpciaccess is required starting from libdrm 2.4.26
DEPENDS = "libpciaccess libpthread-stubs libx11 util-macros libm"


COMMON_DEPENDS += "librt libc libgcc"
DEPENDS += "${COMMON_DEPENDS}"
DEPENDS_${PN} += "${COMMON_DEPENDS}"
RDEPENDS_${PN} += "${COMMON_DEPENDS}"

PACKAGES =+ "${PN}-tests ${PN}-radeon ${PN}-nouveau ${PN}-kms"
PROVIDES_${PN}-kms = "libkms"
PROVIDES_${PN}-radeon =  "libdrm_radeon"
PROVIDES_${PN}-nouveau = "libdrm_nouveau"
PROVIDES_${PN} = "libdrm"

FILES_${PN}-tests = "${bindir}/dr* ${bindir}/mode*"
FILES_${PN}-nouveau = "${libdir}/libdrm_nouveau*.so.*"
FILES_${PN}-radeon = "${libdir}/libdrm_radeon*.so.*"
FILES_${PN}-kms = "${libdir}/libkms*.so.*"


DEPENDS_${PN}-tests     = "${PN} ${PN}-kms"
DEPENDS_${PN}-nouveau   = "${PN}"
RDEPENDS_${PN}-nouveau += "${PN}"
DEPENDS_${PN}-radeon    = "${PN}"
RDEPENDS_${PN}-radeon  += "${PN}"
DEPENDS_${PN}-kms = "libc"

MIRRORS = """
http://mirrors.wayround.org/www.freedesktop.org/dri/dri.freedesktop.org/libdrm/ http://mirrors.wayround.org/www.freedesktop.org/dri/dri.freedesktop.org/libdrm/
"""
