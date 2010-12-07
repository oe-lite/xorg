require xorg-app-common.inc

DESCRIPTION = "The X Keyboard Extension essentially replaces the core protocol definition of keyboard."
HOST_LDFLAGS =+ "-ldl"
DEPENDS += "libxkbfile${RE}-dev xproto${RE}-dev kbproto${RE}-dev libxcb${RE}-dev ${HOST_ARCH}/sysroot-libdl libXau${RE}-dev"
