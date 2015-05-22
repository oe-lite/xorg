PROTO_DEPS += "dri2proto dri3proto presentproto xproto xf86vidmodeproto"
LIB_DEPS += "libdrm libexpat libpthread libdl librt libxcb-glx libxcb-dri2 libxcb-randr libxcb-render libxcb-xfixes libxcb-shape libxcb-sync libxshmfence"
COMMON_RDEPENDS = "libpthread libdl libstdc++ libm libgcc libc"

# most of our targets do not have DRI so will use mesa-xlib
DEFAULT_PREFERENCE = "-1"

DEPENDS += "native:bison"

DRIDRIVERS = "swrast"
PACKAGES =+ "${PN}-swrast ${PN}-swrast-dbg"
FILES_${PN} += "${libdir}/dri/swrast*"
FILES_${PN}-dbg += "${libdir}/dri/.debug/swrast*"
RDEPENDS_${PN} += "${LIB_DEPS} ${COMMON_RDEPENDS} libdrm"
DEPENDS_${PN} += "${LIB_DEPS} ${COMMON_RDEPENDS}"

EXTRA_OECONF += "--with-driver=dri --without-gallium-drivers --with-dri-drivers=${DRIDRIVERS} --with-egl-platforms=x11 --enable-sysfs"

FILES_${PN}-dbg += "${libdir}/dri/.debug/*"

