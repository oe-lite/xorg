SUMMARY = "XCB: The X protocol C binding library"
DESCRIPTION = "The X protocol C-language Binding (XCB) is a replacement \
for Xlib featuring a small footprint, latency hiding, direct access to \
the protocol, improved threading support, and extensibility."
HOMEPAGE = "http://xcb.freedesktop.org"
BUGTRACKER = "https://bugs.freedesktop.org/enter_bug.cgi?product=XCB"

RECIPE_TYPES = "native sdk machine"

# Avoid random rare Doxygen segfaults
EXTRA_OECONF += "--disable-build-docs"

inherit autotools-autoreconf pkgconfig library
LICENSE = "MIT-X"

PARALLEL_MAKE = ""
DEPENDS = "xproto libxau xcb-proto python-xcbgen"

SRC_URI = "http://xcb.freedesktop.org/dist/libxcb-${PV}.tar.bz2"

inherit auto-package-libs library

AUTO_PACKAGE_LIBS = "xcb-composite xcb-damage xcb-dpms xcb-glx \
             xcb-randr xcb-record xcb-render xcb-res \
             xcb-screensaver xcb-shape xcb-shm xcb-sync \
             xcb-xevie xcb-xf86dri xcb-xfixes \
             xcb-xprint xcb-xtest xcb-xv xcb-xvmc \
             xcb-dri2 xcb-xinerama"


AUTO_PACKAGE_LIBS_DEV_DEPENDS = "libxau libxdmcp libc libxcb"
AUTO_PACKAGE_LIBS_DEV_RDEPENDS = "libxau libxdmcp libc libxcb"

PROVIDES_${PN} = "libxcb"

# XCBPROTO_XCBINCLUDEDIR is setup based on `pkg-config --variable=xcbincludedir xcb-proto`
# but the xcbincludedir variable doesn't point into the staging area, so it needs some
# tweeking here:


do_patch[postfuncs] += "do_patch_configure"

do_patch_configure () {
    sed -i "s|XCBPROTO_XCBINCLUDEDIR=\`|XCBPROTO_XCBINCLUDEDIR=${HOST_SYSROOT}/\`|" \
        ${S}/configure.ac
    sed -i "s|XCBPROTO_XCBPYTHONDIR=\`|XCBPROTO_XCBPYTHONDIR=${HOST_SYSROOT}/\`|" \
        ${S}/configure.ac
}

PKG_CONFIG_LIBDIR        =. "${HOST_SYSROOT}${base_libdir}/pkgconfig:"
