require xserver-xorg-common.inc

PROTO_DEPS += "xf86driproto dri2proto glproto"
LIB_DEPS += "mesa-dri-dev mesa-dri-libegl-dev mesa-dri-libgl-dev mesa-dri-libegl mesa-dri-libgl mesa-dri tslib"
DEPENDS_${PN} += "dri2proto"

EXTRA_OECONF += "\
                 --enable-dri \
                 --enable-dri2 \
                 --enable-glx-tls \
                 --with-pic \
                 --with-int10=x86emu \
                 --without-xmlto \
		--enable-tslib --enable-xcalibrate \
"
