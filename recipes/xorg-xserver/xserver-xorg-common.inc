DESCRIPTION = "The X.Org X server"
HOMEPAGE = "http://www.x.org"
LICENSE = "MIT-X"

require conf/fetch/xorg.conf

# xf86-*-* packages depend on an X server built with the xfree86 DDX
# so we have a virtual to represent that:
# deprecated, we should use virtual/xserver instead
PROVIDES_${PN} = "xserver-xf86"

# Other packages tend to just care that there is *an* X server:
PROVIDES_${PN} += "xserver"


XORG_PN = "xorg-server"
SRC_URI = "${XORG_MIRROR}/individual/xserver/${XORG_PN}-${PV}.tar.bz2"
SRC_URI += "file://macro_tweak.patch"

S = "${SRCDIR}/${XORG_PN}-${PV}"

inherit autotools pkgconfig

PROTO_DEPS = "randrproto renderproto fixesproto damageproto xextproto xproto xf86dgaproto xf86miscproto xf86rushproto xf86vidmodeproto xf86bigfontproto compositeproto recordproto resourceproto videoproto scrnsaverproto evieext trapproto xineramaproto fontsproto kbproto inputproto bigreqsproto xcmiscproto glproto"

LIB_DEPS = "pixman libxfont xtrans libxau libxext libxdmcp libdrm libxkbfile libpciaccess openssl libcrypto libm libfreetype libfontenc libz libdl libc libpthread libx11 librt libdbus libxv"
DEPENDS = "${PROTO_DEPS} ${LIB_DEPS} font-util util-macros"
DEPENDS_${PN}		= "${PN}-dev_${PV}"
DEPENDS_${PN}-dev	= ""

RDEPENDS_${PN} += "xkeyboard-config  xserver-xf86-config"
RDEPENDS_${PN} += "libcrypto libxfont libfreetype libfontenc \
            libz libxau pixman libxdmcp libdl libm libc libx11 \
            libpthread libpciaccess libxkbfile libdrm libxv"

# Split out some modules and extensions from the main package
# These aren't needed for basic operations and only take up space:
#  32.0k   libdri.so
#  336.0k  libglx.so
#  1360k   libint10.so
#  180.0k  libwfb.so
#  320.0k  libxaa.so
#  124.0k  libxf1bpp.so
#  84.0k   libxf4bpp.so
#          librecord.so
#          libextmod.so
#          libdbe.so

PACKAGES =+ "${PN}-security-policy \
             ${PN}-sdl \
             ${PN}-fbdev \
             ${PN}-xprint \
             ${PN}-xvfb \
             ${PN}-utils \
             ${PN}-xephyr \
             ${PN}-multimedia-modules \
             ${PN}-extension-dri \
             ${PN}-extension-dri2 \
             ${PN}-extension-glx \
             ${PN}-extension-record \
             ${PN}-extension-extmod \
             ${PN}-extension-dbe \
             ${PN}-module-libint10 \
             ${PN}-module-libafb \
             ${PN}-module-libwfb  \
             ${PN}-module-libmfb \
             ${PN}-module-libcfb \
             ${PN}-module-xaa \
             ${PN}-module-libxf1bpp \
             ${PN}-module-libxf4bpp"

RRECOMMENDS_${PN} += "${PN}-security-policy xkeyboard-config rgb xserver-xf86-config"
RDEPENDS_${PN}-xvfb += "xkeyboard-config"

FILES_${PN} = "${bindir} ${libdir}/X11/Options ${libdir}/X11/Cards ${libdir}/X11/getconfig ${libdir}/X11/etc ${libdir}/modules/*.so ${libdir}/xorg/modules/*.so /etc/X11 ${libdir}/xorg/protocol.txt ${datadir}/X11/xorg.conf.d"
FILES_${PN}-dev += "${libdir}/xorg/modules/*.la ${libdir}/xorg/modules/*/*.la"
FILES_${PN}-doc += "${libdir}/X11/doc ${datadir}/X11/xkb/compiled/README.compiled ${localstatedir}/lib/xkb/README.compiled"
FILES_${PN}-dbg += "${libdir}/xorg/modules/.debug \
                    ${libdir}/xorg/modules/*/.debug \
                    ${libdir}/xorg/modules/*/*/.debug \
                    "
FILES_${PN}-security-policy += "${libdir}/xserver/SecurityPolicy"
FILES_${PN}-sdl = "${bindir}/Xsdl"
FILES_${PN}-fbdev = "${bindir}/Xfbdev"
FILES_${PN}-xprint = "${libdir}/X11/xserver/*/print"
FILES_${PN}-xvfb = "${bindir}/Xvfb"
FILES_${PN}-utils = "${bindir}/scanpci ${bindir}/pcitweak ${bindir}/ioport ${bindir}/in[bwl] ${bindir}/out[bwl] ${bindir}/mmap[rw] ${bindir}/gtf ${bindir}/getconfig ${bindir}/getconfig.pl"
FILES_${PN}-xephyr = "${bindir}/Xephyr"
FILES_${PN}-multimedia-modules = "${libdir}/xorg/modules/multimedia/*drv*"
FILES_${PN}-extension-dri = "${libdir}/xorg/modules/extensions/libdri.so"
FILES_${PN}-extension-dri2 = "${libdir}/xorg/modules/extensions/libdri2.so"
FILES_${PN}-extension-glx = "${libdir}/xorg/modules/extensions/libglx.so"
FILES_${PN}-extension-record = "${libdir}/xorg/modules/extensions/librecord.so"
FILES_${PN}-extension-extmod = "${libdir}/xorg/modules/extensions/libextmod.so"
FILES_${PN}-extension-dbe = "${libdir}/xorg/modules/extensions/libdbe.so"
FILES_${PN}-module-libint10 = "${libdir}/xorg/modules/libint10.so"
FILES_${PN}-module-libafb = "${libdir}/xorg/modules/libafb.so"
FILES_${PN}-module-libwfb = "${libdir}/xorg/modules/libwfb.so"
FILES_${PN}-module-libmfb = "${libdir}/xorg/modules/libmfb.so"
FILES_${PN}-module-libcfb = "${libdir}/xorg/modules/libcfb.so"
FILES_${PN}-module-xaa = "${libdir}/xorg/modules/libxaa.so"
FILES_${PN}-module-libxf1bpp = "${libdir}/xorg/modules/libxf1bpp.so"
FILES_${PN}-module-libxf4bpp = "${libdir}/xorg/modules/libxf4bpp.so"

#xinerama support
RECIPE_FLAGS += "x_xinerama"
DEPENDS:>USE_x_xinerama += " libxinerama"
XINERAMA_CONF                = "--disable-xinerama"
XINERAMA_CONF:USE_x_xinerama = "--enable-xinerama"
RDEPENDS_${PN}:>USE_x_xinerama += " libxinerama"

EXTRA_OECONF += "${XINERAMA_CONF} \
	         --with-fop=no \
                 --disable-static \
                 --disable-acfb \
                 --disable-ccfb \
                 --disable-mcfb \
                 --disable-xf86misc \
                 --disable-xorgcfg \
                 --disable-record \
                 --disable-dmx \
                 --disable-xnest \
                 --disable-xvfb \
                 --enable-composite \
                 --without-dtrace \
                 --sysconfdir=/etc/X11 \
                 --localstatedir=/var \
                 --with-fontdir=${datadir}/fonts/X11 \
                 --with-xkb-output=/var/lib/xkb \
                 ac_cv_file__usr_share_sgml_X11_defs_ent=no \
"

MACHINE_CFLAGS += "-I${MACHINE_SYSROOT}${includedir}/pixman-1"

PACKAGECONFIG ??= "udev"
PACKAGECONFIG[hal] = "--enable-config-hal,--disable-config-hal,,hal"
PACKAGECONFIG[udev] = "--enable-config-udev,--disable-config-udev,udev"

do_install[postfuncs] += "do_install_append"
do_install_append () {
	# Its assumed base-files creates this for us
	rmdir ${D}${localstatedir}/log/
}