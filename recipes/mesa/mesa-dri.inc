PROTO_DEPS += "dri2proto xproto xf86vidmodeproto"
LIB_DEPS += "libdrm libexpat libpthread libdl librt"
COMMON_RDEPENDS = "libdrm libpthread libdl libstdc++ libm libgcc libc"

# most of our targets do not have DRI so will use mesa-xlib
DEFAULT_PREFERENCE = "-1"

DRIDRIVERS = "swrast"
PACKAGES =+ "${PN}-swrast ${PN}-swrast-dbg"
FILES_${PN}-swrast = "${libdir}/dri/swrast*"
FILES_${PN}-swrast-dbg = "${libdir}/dri/.debug/swrast*"
RDEPENDS_${PN}-swrast += "libexpat ${COMMON_RDEPENDS}"
DEPENDS_${PN} += "libxdamage libxxf86vm"

EXTRA_OECONF += "--with-driver=dri --without-gallium-drivers --with-dri-drivers=${DRIDRIVERS} --with-egl-platforms=x11"

FILES_${PN}-dbg += "${libdir}/dri/.debug/*"
