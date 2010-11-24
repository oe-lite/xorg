require xorg-lib-common.inc
DESCRIPTION = "X11 toolkit intrinsics library"
DEPENDS += "libICE${RE}-dev libSM${RE}-dev libX11${RE}-dev kbproto${RE}-dev"
PR = "${INC_PR}.0"

EXTRA_OECONF += "--disable-install-makestrs --disable-xkb"

do_compile() {
        (
                unset CC LD CXX CCLD
                oe_runmake -C util 'XT_CFLAGS=' 'CC=${BUILD_CC}' 'LD=${BUILD_LD}' 'CXX=${BUILD_CXX}' 'CCLD=${BUILD_CCLD}' 'CFLAGS=-D_GNU_SOURCE  ${BUILD_CFLAGS}' 'LDFLAGS=${BUILD_LDFLAGS}' 'CXXFLAGS=${BUILD_CXXFLAGS}' 'CPPFLAGS=${BUILD_CPPFLAGS}' makestrs
        ) || exit 1
        oe_runmake
}

BBCLASSEXTEND = "native"
