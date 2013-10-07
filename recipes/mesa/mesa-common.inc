SUMMARY = "A free implementation of the OpenGL API"
DESCRIPTION = "Mesa is an open-source implementation of the OpenGL specification - \
a system for rendering interactive 3D graphics.  \
A variety of device drivers allows Mesa to be used in many different environments \
ranging from software emulation to complete hardware acceleration for modern GPUs. \
Mesa is used as part of the overall Direct Rendering Infrastructure and X.org \
environment."

HOMEPAGE = "http://mesa3d.org"
BUGTRACKER = "https://bugs.freedesktop.org"
LICENSE = "MIT"

PROTO_DEPS = "xf86driproto glproto"
LIB_DEPS = "libx11 libxext libxxf86vm libxdamage libxfixes"

DEPENDS = "native:makedepend native:python-runtime native:libxml2 ${PROTO_DEPS} ${LIB_DEPS}"
DEPENDS_${PN}-dev += "xf86driproto glproto"

inherit autotools-autoreconf pkgconfig auto-package-libs c make c++

EXTRA_OECONF = "--enable-glu \
                --disable-glw \
                --disable-glut \
		--enable-glx-tls\
		"
FILES_${PN}-libegl-dev += "${includedir}/EGL \
		       	   ${libdir}/pkgconfig/egl.pc "

FILES_${PN}-libgl-dev += "${includedir}/GL \
                          ${libdir}/pkgconfig/gl.pc "

AUTO_PACKAGE_LIBS = "EGL GL GLU OSMesa"
AUTO_PACKAGE_LIBS_DEV_DEPENDS = "${PN}-dev ${COMMON_RDEPENDS} libxxf86vm libxdamage libxfixes"
AUTO_PACKAGE_LIBS_RDEPENDS = "${COMMON_RDEPENDS} libxxf86vm libxdamage libxfixes"
