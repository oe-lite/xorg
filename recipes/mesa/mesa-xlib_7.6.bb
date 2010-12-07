include mesa-common.inc

PROTO_DEPS = "xf86driproto${RE}-dev glproto${RE}-dev"
LIB_DEPS = "libX11${RE}-dev libxext${RE}-dev libxxf86vm${RE}-dev libXdamage${RE}-dev libXfixes${RE}-dev"

DEPENDS = "${PROTO_DEPS}  ${LIB_DEPS}"

SRC_URI = "ftp://ftp.freedesktop.org/pub/mesa/${PV}/MesaLib-${PV}.tar.bz2;name=archive \
           ftp://ftp.freedesktop.org/pub/mesa/${PV}/MesaDemos-${PV}.tar.bz2;name=demos \
          "

PR = "${INC_PR}.0"

EXTRA_OECONF += "--disable-gallium --with-driver=xlib"
