HOMEPAGE = "http://www.x.org"
SECTION = "x11/base"
LICENSE = "MIT-X"

INC_PR = "r0"
inherit autotools pkgconfig

# No udev, hal and xsdl support
EXTRA_OECONF += " \
--disable-config-hal \
--disable-config-udev \
--disable-xsdl \
"

MACHINE_CPPFLAGS += "-I${MACHINE_SYSROOT}${includedir}/pixman-1"
 
require conf/mirror.conf
SRC_URI = "${XORG_MIRROR}/individual/xserver/${BPN}-${PV}.tar.bz2"
#file://pixman-fix.patch;patch=1"

DEPENDS = "freetype${RE}-dev flex-native kbproto${RE}-dev \ 
glproto${RE}-dev randrproto${RE}-dev renderproto${RE}-dev \
fixesproto${RE}-dev damageproto${RE}-dev \
xcmiscproto${RE}-dev xextproto${RE}-dev xproto${RE}-dev \
xf86vidmodeproto${RE}-dev  \
scrnsaverproto${RE}-dev resourceproto${RE}-dev \
fontsproto${RE}-dev inputproto${RE}-dev \
xf86dgaproto${RE}-dev videoproto${RE}-dev \
dri2proto${RE}-dev \
compositeproto${RE}-dev trapproto${RE}-dev recordproto${RE}-dev \
xineramaproto${RE}-dev xtrans${RE}-dev libxkbfile${RE}-dev \
libXfont${RE}-dev libXfont${RE} libXau${RE}-dev \
libXdmcp${RE}-dev \
libxkbui${RE}-dev \
pixman${RE}-dev \
openssl${RE}-dev \
bigreqsproto${RE}-dev \
util-macros${RE}-dev \
libpciaccess${RE}-dev \
${HOST_ARCH}/sysroot-libm \
${HOST_ARCH}/sysroot-libdl \
libfontenc${RE}-dev libfontenc${RE} \
zlib${RE} zlib${RE}-dev \
"

RDEPENDS_${PN} += "libpciaccess pixman libXfont libXau libXdmcp freetype zlib libfontenc \
	${HOST_ARCH}/sysroot-libdl ${HOST_ARCH}/sysroot-libm \
	"

# Removed deps: fontconfig liblbxutil xf86driproto drm xf86miscproto xf86bigfontproto dmxproto evieext libfontenc
# libxxf86vm libxaw libxmu libxt libxpm libxext libx11
# libxxf86misc libxi libdmx libxtst libxres virtual/libgl libxcalibrate
# libxv ${DISTRO_XORG_CONFIG_MANAGER}"

#EXTRA_OECONF += " \
#--disable-dmx \
#--disable-dri \
#--disable-dri2 \
#--disable-glx \
#--disable-hal \
#--disable-ipv6 \
#--disable-kdrive \
#--disable-kdrive-vesa \
#--disable-libxf86config \
#--disable-nptl \
#--disable-record \
#--disable-tslib \
#--disable-unit-tests \
#--disable-xephyr \
#--disable-xfake \
#--disable-xfbdev \
#--disable-xfree86-utils \
#--disable-xnest \
#--disable-xorg  \
#--disable-xsdl \
#--enable-xcalibrate \
#ac_cv_file__usr_share_sgml_X11_defs_ent=no \
#"


EXTRA_OECONF += " \
--disable-acfb \
--disable-ccfb \
--disable-dga \
--disable-dmx \
--disable-dri \
--disable-dri2 \
--disable-glx \
--disable-mcfb \
--disable-record \
--disable-static \
--disable-xf86misc \
--disable-xinerama \
--disable-xnest \
--disable-xorgcfg \
--disable-xvfb \
--enable-composite \
--localstatedir=/var \
--sysconfdir=/etc/X11 \
--with-fontdir=/usr/share/fonts/X11 \
--with-xkb-output=/var/lib/xkb \
ac_cv_file__usr_share_sgml_X11_defs_ent=no \
"

FILES_${PN}-dev += "${libdir}/xorg/modules/*.la ${libdir}/xorg/modules/*.a ${libdir}/xorg/modules/*/*.la ${libdir}/xorg/modules/*/*.a"
FILES_${PN}-utils = "${bindir}/scanpci ${bindir}/pcitweak ${bindir}/ioport ${bindir}/in[bwl] ${bindir}/out[bwl] ${bindir}/mmap[rw] ${bindir}/gtf ${bindir}/getconfig ${bindir}/getconfig.pl"
FILES_${PN} += "${libdir}/X11/Options ${libdir}/X11/Cards ${libdir}/X11/getconfig ${libdir}/X11/etc ${libdir}/xserver/SecurityPolicy ${libdir}/xorg/modules/*.so ${libdir}/xorg/modules/*/*.so ${libdir}/xorg/modules/*/*/*.so /etc/X11 "
FILES_${PN}-doc += "${libdir}/X11/doc /var/lib/xkb/README.compiled /usr/lib/xorg/protocol.txt"

FILES_${PN}-dbg += "${libdir}/xorg/modules/.debug \
                    ${libdir}/xorg/modules/*/.debug \
		    ${libdir}/xorg/modules/*/*/.debug \
		    "

#NOTE:   /usr/lib/xorg/protocol.txt
#NOTE:   /usr/lib/xorg/modules/libxaa.la
#NOTE:   /usr/lib/xorg/modules/libshadowfb.a
#NOTE:   /usr/lib/xorg/modules/libxaa.so
#NOTE:   /usr/lib/xorg/modules/libshadowfb.la
#NOTE:   /usr/lib/xorg/modules/libvgahw.a
#NOTE:   /usr/lib/xorg/modules/libexa.la
#NOTE:   /usr/lib/xorg/modules/libfb.so
#NOTE:   /usr/lib/xorg/modules/libvbe.la
#NOTE:   /usr/lib/xorg/modules/libfbdevhw.la
#NOTE:   /usr/lib/xorg/modules/libfbdevhw.so
#NOTE:   /usr/lib/xorg/modules/libfb.la
#NOTE:   /usr/lib/xorg/modules/libexa.so
#NOTE:   /usr/lib/xorg/modules/libint10.so
#NOTE:   /usr/lib/xorg/modules/libwfb.a
#NOTE:   /usr/lib/xorg/modules/libxaa.a
#NOTE:   /usr/lib/xorg/modules/libshadow.a
#NOTE:   /usr/lib/xorg/modules/libint10.la
#NOTE:   /usr/lib/xorg/modules/libvbe.a
#NOTE:   /usr/lib/xorg/modules/libwfb.la
#NOTE:   /usr/lib/xorg/modules/libvgahw.so
#NOTE:   /usr/lib/xorg/modules/libfb.a
#NOTE:   /usr/lib/xorg/modules/libvbe.so
#NOTE:   /usr/lib/xorg/modules/libshadowfb.so
#NOTE:   /usr/lib/xorg/modules/libfbdevhw.a
#NOTE:   /usr/lib/xorg/modules/libshadow.la
#NOTE:   /usr/lib/xorg/modules/libxf8_16bpp.la
#NOTE:   /usr/lib/xorg/modules/libint10.a
#NOTE:   /usr/lib/xorg/modules/libexa.a
#NOTE:   /usr/lib/xorg/modules/libxf8_16bpp.so
#NOTE:   /usr/lib/xorg/modules/libwfb.so
#NOTE:   /usr/lib/xorg/modules/libxf8_16bpp.a
#NOTE:   /usr/lib/xorg/modules/libshadow.so
#NOTE:   /usr/lib/xorg/modules/libvgahw.la
#NOTE:   /usr/lib/xorg/modules/extensions/libextmod.la
#NOTE:   /usr/lib/xorg/modules/extensions/libdbe.a
#NOTE:   /usr/lib/xorg/modules/extensions/libextmod.so
#NOTE:   /usr/lib/xorg/modules/extensions/libdbe.so
#NOTE:   /usr/lib/xorg/modules/extensions/libextmod.a
#NOTE:   /usr/lib/xorg/modules/extensions/libdbe.la
#NOTE:   /usr/lib/xorg/modules/extensions/.debug/libextmod.so
#NOTE:   /usr/lib/xorg/modules/extensions/.debug/libdbe.so
#NOTE:   /usr/lib/xorg/modules/.debug/libxaa.so
#NOTE:   /usr/lib/xorg/modules/.debug/libfb.so
#NOTE:   /usr/lib/xorg/modules/.debug/libfbdevhw.so
#NOTE:   /usr/lib/xorg/modules/.debug/libexa.so
#NOTE:   /usr/lib/xorg/modules/.debug/libint10.so
#NOTE:   /usr/lib/xorg/modules/.debug/libvgahw.so
#NOTE:   /usr/lib/xorg/modules/.debug/libvbe.so
#NOTE:   /usr/lib/xorg/modules/.debug/libshadowfb.so
#NOTE:   /usr/lib/xorg/modules/.debug/libxf8_16bpp.so
#NOTE:   /usr/lib/xorg/modules/.debug/libwfb.so
#NOTE:   /usr/lib/xorg/modules/.debug/libshadow.so
#NOTE:   /usr/lib/xorg/modules/multimedia/bt829_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/uda1380_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/uda1380_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/tda8425_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/tda9885_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/fi1236_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/tda9885_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/msp3430_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/tda9850_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/fi1236_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/fi1236_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/tda8425_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/uda1380_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/msp3430_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/tda9850_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/bt829_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/msp3430_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/bt829_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/tda8425_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/tda9850_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/tda9885_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/tda8425_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/tda9885_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/msp3430_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/fi1236_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/uda1380_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/tda9850_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/bt829_drv.so##
