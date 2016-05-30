DESCRIPTION = "The X.Org X server"
HOMEPAGE = "http://www.x.org"
LICENSE = "MIT-X"

require conf/fetch/xorg.conf
require conf/xorg.conf

# Other packages tend to just care that there is *an* X server:
PROVIDES_${PN} += "xserver"

XORG_PN = "xorg-server"
SRC_URI = "${XORG_MIRROR}/individual/xserver/${XORG_PN}-${PV}.tar.bz2"
SRC_URI += "file://macro_tweak.patch"

S = "${SRCDIR}/${XORG_PN}-${PV}"

inherit autotools-autoreconf pkgconfig

AUTORECONF_CMD = " \
   ${LIBTOOLIZE} --force --automake --copy \
&& aclocal $acpaths --force \
&& autoconf $acpaths --force \
&& automake -a --copy --force; \
"


PROTO_DEPS = "randrproto renderproto fixesproto damageproto xextproto \
	   xproto xf86miscproto xf86rushproto \
	   xf86bigfontproto compositeproto resourceproto videoproto evieext \
	   trapproto fontsproto kbproto inputproto bigreqsproto xcmiscproto"

LIB_DEPS = "pixman libxfont libxext libxkbfile libdl libpthread \
	    libssl libpciaccess libcrypto"

RECIPE_FLAGS += "dbus_x11"
LIB_DEPS:>USE_dbus_x11 = " libdbus"

DEPENDS = "${PROTO_DEPS} ${LIB_DEPS} xtrans font-util util-macros"
DEPENDS_${PN}		= "${PN}-dev_${PV}"
DEPENDS_${PN}-dev	= ""
DEPENDS_${PN}[qa] = "allow-missing-lib-depends"

RDEPENDS_${PN} += "xkeyboard-config  xserver-xf86-config"
RDEPENDS_${PN} += "${LIB_DEPS}"


XSERVER_USE_FLAGS += "dmps=1"
XSERVER_USE_FLAGS += "screensaver=1"
XSERVER_USE_FLAGS += "composite=1"
XSERVER_USE_FLAGS += "xres=1"
XSERVER_USE_FLAGS += "xf86vidmode=1"
XSERVER_USE_FLAGS += "xace=1"
XSERVER_USE_FLAGS += "xvmc=1"
XSERVER_USE_FLAGS += "sparkle=1"
XSERVER_USE_FLAGS += "xdmcp=1"
XSERVER_USE_FLAGS += "xvfb=1"
XSERVER_USE_FLAGS += "xv=1"
XSERVER_USE_FLAGS += "xinerama=1"
XSERVER_USE_FLAGS += "record=1"
XSERVER_USE_FLAGS += "xnest=1"
XSERVER_USE_FLAGS += "vbe=1"
XSERVER_USE_FLAGS += "xaa=1"
XSERVER_USE_FLAGS += "dbe=1"
XSERVER_USE_FLAGS += "dga=1"
XSERVER_USE_FLAGS += "dri=1"
XSERVER_USE_FLAGS += "dri2=1"
XSERVER_USE_FLAGS += "int10=1:int10-module"
XSERVER_USE_FLAGS += "aiglx=1"
XSERVER_USE_FLAGS += "glx-tls=1"
XSERVER_USE_FLAGS += "glx=1"
XSERVER_USE_FLAGS += "libdrm=1"
XSERVER_CONF = ""

DEPENDS:>USE_xserver_xf86vidmode = " xf86vidmodeproto"
DEPENDS:>USE_xserver_screensaver = " scrnsaverproto"
DEPENDS:>USE_xserver_record      = " recordproto"
DEPENDS:>USE_xserver_dri         = " glproto xf86driproto dri2proto mesa-dri-libgl"
DEPENDS:>USE_xserver_dga         = " xf86dgaproto"
DEPENDS_${PN}:>USE_xserver_dri   = " glproto xf86driproto dri2proto mesa-dri-dev"
RDEPENDS_${PN}:>USE_xserver_dri  = " libgl ${PN}-extension-dri mesa-dri"
RDEPENDS_${PN}:>USE_xserver_dri2  = " ${PN}-extension-dri2"
RDEPENDS_${PN}:>USE_xserver_glx  = " ${PN}-extension-glx"
RDEPENDS_${PN}:>USE_xserver_record  = " ${PN}-extension-record"
RDEPENDS_${PN}:>USE_xserver_dbe  = " ${PN}-extension-dbe"
RDEPENDS_${PN}:>USE_xserver_dga  = " ${PN}-extension-dga"
DEPENDS:>USE_xserver_xinerama    = " libxinerama"
DEPENDS_${PN}:>USE_xserver_xinerama    = " xineramaproto"
RDEPENDS_${PN}:>USE_xserver_xinerama = " libxinerama"
RDEPENDS_${PN}:>USE_xserver_libdrm      = " libdrm "
AUTO_PACKAGE_LIBS_DEV_DEPENDS:>USE_xserver_libdrm = " libdrm "

RDEPENDS_${PN} += " ${PN}-extension-extmod"

EXTRA_OECONF += "${XSERVER_CONF} \
	         --with-fop=no \
                 --disable-static \
                 --without-dtrace \
                 --sysconfdir=/etc/X11 \
                 --localstatedir=/var \
                 --with-xkb-output=/var/lib/xkb \
		 --disable-option-checking \
                 ac_cv_file__usr_share_sgml_X11_defs_ent=no \
"

MACHINE_CFLAGS += "-I${MACHINE_SYSROOT}${includedir}/pixman-1"

do_install[postfuncs] += "do_install_append"
do_install_append () {
	# Its assumed base-files creates this for us
	rmdir ${D}${localstatedir}/log/
}

inherit auto-package-utils auto-package-libs

SOLIBS = ".so"
AUTO_PACKAGE_LIBS_PKGPREFIX = "extension-"
AUTO_PACKAGE_LIBS_DEV_DEPENDS = "libc libm libdl libpixman \
			      libpciaccess librt"
AUTO_PACKAGE_LIBS_RDEPENDS = "libc libm libdl libpixman \
			      libpciaccess librt"
AUTO_PACKAGE_UTILS_RDEPENDS = "libc libm ${LIB_DEPS}"
AUTO_PACKAGE_LIBS_LIBDIR += "${libdir}/xorg/modules/extensions \
			     ${libdir}/xorg/modules"

AUTO_PACKAGE_LIBS = "record composite exa fb fbdevhw int10 \
		     shadow shadowfb vbe vgahw xaa wfb dga dbe \
		     dri2 dri extmod glx \
		     "
AUTO_PACKAGE_UTILS = "scanpci pcitweak ioport inb inw inl gtf \
		      outb outw outl mmapr mmapw getconfig getconfig.pl \
		      cvt Xvfb Xnest\
		      "

FILES_${PN} = """
            ${bindir}
	    ${libdir}/X11/Options
	    ${libdir}/X11/Cards
	    ${libdir}/X11/getconfig
	    ${libdir}/X11/etc
	    /etc/X11
	    ${datadir}/X11/xorg.conf.d
	    """

FILES_${PN}-doc += "${libdir}/X11/doc \
      	        ${libdir}/xorg/protocol.txt \
		${datadir}/X11/xkb/compiled/README.compiled \
		${localstatedir}/lib/xkb/README.compiled"
FILES_${PN}-dbg += "${libdir}/xorg/modules/.debug \
                    ${libdir}/xorg/modules/*/.debug \
                    ${libdir}/xorg/modules/*/*/.debug \
                    "
PACKAGES =+ "${PN}-multimedia-modules ${PN}-multimedia-modules-dev"
FILES_${PN}-multimedia-modules = "${libdir}/xorg/modules/multimedia/*drv*"
FILES_${PN}-multimedia-modules-dev = "${libdir}/xorg/modules/multimedia/*"

# this is were the magic happens
addhook xorg_use_flags to post_recipe_parse first before set_useflags
def xorg_use_flags(d):
    pn = d.get("PN")
    for flag in (d.get("XSERVER_USE_FLAGS") or "").split():
        try:
            flag, config = flag.split(":",1)
        except ValueError:
	    config = None
        try:
            flag, default = flag.split("=", 1)
        except ValueError:
            default = "0"
        useflag = "xserver_" + flag.replace("-", "_")
        d.append("RECIPE_FLAGS", useflag, " ")
	if config is None:
	   config = flag
        if default != "0":
            d.set("DEFAULT_USE_" + useflag, default)
        if config != '' and default != "0":
            d.set("XSERVER_CONF_" + flag , "--disable-" + config)
            d.set_override("XSERVER_CONF_%s"%(flag), ("", "USE_" + useflag),
                           " --enable-%s"%(config))
        elif default != "0":
            d.set("XSERVER_CONF_" + flag , "--disable-" + flag)
            d.set_override("XSERVER_CONF_%s"%(flag), ("", "USE_" + useflag),
                           " --enable-%s"%(flag))
	
        d.append("XSERVER_CONF", " ${" + "XSERVER_CONF_" + flag + "} ")
