include mesa-common.inc

PROTO_DEPS = "xf86driproto${RE}-dev glproto${RE}-dev dri2proto${RE}-dev expat${RE}-dev"
LIB_DEPS = "libdrm${RE}-dev libX11${RE}-dev libxext${RE}-dev libxxf86vm${RE}-dev libXdamage${RE}-dev libXfixes${RE}-dev"

DEPENDS = "${PROTO_DEPS}  ${LIB_DEPS}"

SRC_URI = "ftp://ftp.freedesktop.org/pub/mesa/${PV}/MesaLib-${PV}.tar.bz2;name=archive \
           ftp://ftp.freedesktop.org/pub/mesa/${PV}/MesaDemos-${PV}.tar.bz2;name=demos \
          "
PR = "${INC_PR}.0"

# most of our targets do not have DRI so will use mesa-xlib
DEFAULT_PREFERENCE = "-1"

PACKAGES =+ "${PN}-xprogs"

FILES_${PN} += "${libdir}/dri/*.so"
FILES_${PN}-dbg += "${libdir}/dri/.debug/*"
FILES_${PN}-xprogs = "${bindir}/glxdemo ${bindir}/glxgears ${bindir}/glxheads ${bindir}/glxinfo"

EXTRA_OECONF += "--disable-gallium --with-driver=dri --with-dri-drivers=swrast,${MACHINE_DRI_MODULES}"
