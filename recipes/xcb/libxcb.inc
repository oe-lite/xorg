DESCRIPTION = "XCB: an X protocol C binding"
SECTION = "x11/libs"
LICENSE = "MIT-X"
HOMEPAGE = "http://xcb.freedesktop.org"

PARALLEL_MAKE = ""
BBCLASSEXTEND = "native sdk"
DEPENDS = "xcb-proto${RE}-dev xproto${RE}-dev libXau${RE}-dev \
libxslt-native-dev libxml2-native-dev libpthread-stubs${RE}-dev \
"
INC_PR = "r0"

SRC_URI = "http://xcb.freedesktop.org/dist/${BPN}-${PV}.tar.bz2 \
"

PACKAGES =+ "libxcb${RE}-composite libxcb${RE}-damage libxcb${RE}-dpms libxcb${RE}-glx \
             libxcb${RE}-randr libxcb${RE}-record libxcb${RE}-render libxcb${RE}-res \
             libxcb${RE}-screensaver libxcb${RE}-shape libxcb${RE}-shm libxcb${RE}-sync \
             libxcb${RE}-xevie libxcb${RE}-dri2 libxcb${RE}-xf86dri libxcb${RE}-xfixes \
             libxcb${RE}-xinerama libxcb${RE}-xlib libxcb${RE}-xprint libxcb${RE}-xtest \
             libxcb${RE}-xv libxcb${RE}-xvmc"


FILES_${PN} = "${libdir}/libxcb.so.*"
FILES_${PN}-composite = "${libdir}/libxcb-composite.so.*"
FILES_${PN}-damage = "${libdir}/libxcb-damage.so.*"
FILES_${PN}-dpms = "${libdir}/libxcb-dpms.so.*"
FILES_${PN}-glx = "${libdir}/libxcb-glx.so.*"
FILES_${PN}-randr = "${libdir}/libxcb-randr.so.*"
FILES_${PN}-record = "${libdir}/libxcb-record.so.*"
FILES_${PN}-render = "${libdir}/libxcb-render.so.*"
FILES_${PN}-res = "${libdir}/libxcb-res.so.*"
FILES_${PN}-screensaver = "${libdir}/libxcb-screensaver.so.*"
FILES_${PN}-shape = "${libdir}/libxcb-shape.so.*"
FILES_${PN}-shm = "${libdir}/libxcb-shm.so.*"
FILES_${PN}-sync = "${libdir}/libxcb-sync.so.*"
FILES_${PN}-xevie = "${libdir}/libxcb-xevie.so.*"
FILES_${PN}-xf86dri = "${libdir}/libxcb-xf86dri.so.*"
FILES_${PN}-dri2 = "${libdir}/libxcb-dri2.so.*"
FILES_${PN}-xfixes = "${libdir}/libxcb-xfixes.so.*"
FILES_${PN}-xinerama = "${libdir}/libxcb-xinerama.so.*"
FILES_${PN}-xlib = "${libdir}/libxcb-xlib.so.*"
FILES_${PN}-xprint = "${libdir}/libxcb-xprint.so.*"
FILES_${PN}-xtest = "${libdir}/libxcb-xtest.so.*"
FILES_${PN}-xv = "${libdir}/libxcb-xv.so.*"
FILES_${PN}-xvmc = "${libdir}/libxcb-xvmc.so.*"

inherit autotools pkgconfig
