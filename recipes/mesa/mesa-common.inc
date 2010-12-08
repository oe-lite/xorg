SECTION = "x11"

DESCRIPTION = "An open source implementation of the OpenGL spec"
HOMEPAGE = "http://mesa3d.org"
LICENSE = "MIT"

INC_PR = "r0"

SRC_URI = "${SOURCEFORGE_MIRROR}/mesa3d/MesaLib-${PV}.tar.bz2;name=archive \
           ${SOURCEFORGE_MIRROR}/mesa3d/MesaDemos-${PV}.tar.bz2;name=demos "
S = "${WORKDIR}/Mesa-${PV}"

inherit autotools pkgconfig

EXTRA_OECONF = "--enable-glu \
                --disable-glw \
                --disable-glut \
	       "

PACKAGES =+ "libegl libegl-dev libglu libglu-dev libosmesa libosmesa-dev libgl libgl-dev"
FILES_libegl = "${libdir}/libEGL${SOLIBS}"
FILES_libgl = "${libdir}/libGL${SOLIBS}"
FILES_libglu = "${libdir}/libGLU${SOLIBS}"
FILES_libosmesa = "${libdir}/libOSMesa${SOLIBS}"

FILES_libegl-dev = "${libdir}/libEGL.* ${includedir}/EGL"
FILES_libgl-dev = "${libdir}/libGL.* ${includedir}/GL"
FILES_libglu-dev = "${libdir}/libGLU.* ${includedir}/GL/glu*.h"
FILES_libosmesa-dev = "${libdir}/libOSMesa.* ${includedir}/osmesa.h"


do_stage() {
        autotools_stage_all
		install -d ${STAGING_INCDIR}/GL/	
		cp -pPr ${S}/include/GL/internal* ${STAGING_INCDIR}/GL/
}

do_install_append () {
    install -d ${D}/${bindir}
    for i in glxdemo glxgears glxheads glxinfo; do 
        install -m 0755 ${S}/progs/xdemos/${i} ${D}/${bindir}
    done
}