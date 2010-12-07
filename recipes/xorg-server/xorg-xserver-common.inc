HOMEPAGE = "http://www.x.org"
SECTION = "x11/base"
LICENSE = "MIT-X"

INC_PR = "r0"

DEPENDS = "fontconfig${RE}-dev freetype${RE}-dev flex-native${RE}-dev lbxutil${RE}-dev kbproto${RE}-dev \
xf86driproto${RE}-dev libdrm${RE}-dev glproto${RE}-dev randrproto${RE}-dev renderproto${RE}-dev fixesproto${RE}-dev damageproto${RE}-dev \
xcmiscproto${RE}-dev xextproto${RE}-dev xproto${RE}-dev xf86miscproto${RE}-dev xf86vidmodeproto${RE}-dev xf86bigfontproto${RE}-dev \
scrnsaverproto${RE}-dev bigreqsproto${RE}-dev resourceproto${RE}-dev fontsproto${RE}-dev inputproto${RE}-dev \
xf86dgaproto${RE}-dev videoproto${RE}-dev compositeproto${RE}-dev trapproto${RE}-dev recordproto${RE}-dev dmxproto${RE}-dev \
resourceproto${RE}-dev xineramaproto${RE}-dev xtrans${RE}-dev evieext${RE}-dev libxkbfile${RE}-dev libxfont${RE}-dev libxau${RE}-dev \
libfontenc${RE}-dev libxdmcp${RE}-dev libxxf86vm${RE}-dev libXaw${RE}-dev libxmu${RE}-dev libXt${RE}-dev libXpm${RE}-dev libxext${RE}-dev libx11${RE}-dev \
libxkbui${RE}-dev libxxf86misc${RE}-dev libxi${RE}-dev libdmx${RE}-dev libxtst${RE}-dev libxres${RE}-dev libgl${RE}-dev libxcalibrate${RE}-dev \
libxv${RE}-dev"

#RRECOMMENDS_${PN} = "libpciaccess"

SRC_URI = "${XORG_MIRROR}/individual/xserver/${BPN}-${PV}.tar.bz2;name=archive"

inherit autotools pkgconfig
# glx-use-tls

EXTRA_OECONF += " --enable-xcalibrate \
                  --enable-kdrive \
                  --enable-xephyr \
                  --disable-xfbdev \
                  --disable-xnest \
                  --disable-kdrive-vesa \
                  --with-default-font-path="/usr/share/fonts/X11/misc" \
                  ac_cv_file__usr_share_sgml_X11_defs_ent=no"

# CONFIG_MANAGER_OPTION is used only in recipes which support those options

EXTRA_OECONF_append_arm = " ac_cv_header_linux_apm_bios_h=no "

PACKAGES =+ "xserver-security-policy"
FILES_xserver-security-policy += "${libdir}/xserver/SecurityPolicy"

#RRECOMMENDS_${PN} += "xserver-security-policy xkeyboard-config xorg-minimal-fonts rgb xserver-xorg-conf"

PACKAGES =+ "${PN}-sdl ${PN}-fbdev ${PN}-xprint ${PN}-xvfb ${PN}-utils ${PN}-xephyr"

RDEPENDS_${PN}-xvfb += "xkeyboard-config xorg-minimal-fonts"

FILES_${PN}-fbdev = "${bindir}/Xfbdev"
FILES_${PN}-sdl = "${bindir}/Xsdl"
FILES_${PN}-xprint = "${libdir}/X11/xserver/*/print"
FILES_${PN}-xvfb = "${bindir}/Xvfb"
FILES_${PN}-utils = "${bindir}/scanpci ${bindir}/pcitweak ${bindir}/ioport ${bindir}/in[bwl] ${bindir}/out[bwl] ${bindir}/mmap[rw] ${bindir}/gtf ${bindir}/getconfig ${bindir}/getconfig.pl"
FILES_${PN} = "${bindir} ${libdir}/X11/Options ${libdir}/X11/Cards ${libdir}/X11/getconfig ${libdir}/X11/etc ${libdir}/modules ${libdir}/xorg/modules /etc/X11 ${libdir}/xorg/protocol.txt"
FILES_${PN}-doc += "${libdir}/X11/doc /usr/share/X11/xkb/compiled/README.compiled"
FILES_${PN}-xephyr = "${bindir}/Xephyr"

FILES_${PN}-dbg += "${libdir}/xorg/modules/.debug \
                    ${libdir}/xorg/modules/*/.debug \
		    ${libdir}/xorg/modules/*/*/.debug \
		    "

# Split out some modules and extensions from the main package
# These aren't needed for basic operations and only take up space:

PACKAGES =+ "${PN}-extension-dri \
             ${PN}-extension-dri2 \
             ${PN}-extension-glx \
             ${PN}-module-libint10 \
             ${PN}-module-libafb \
             ${PN}-module-libwfb  \
             ${PN}-module-libmfb \
             ${PN}-module-libcfb \
             ${PN}-module-xaa \
             ${PN}-module-libxf1bpp \
             ${PN}-module-libxf4bpp"

FILES_${PN}-extension-dri = "${libdir}/xorg/modules/extensions/libdri.so"
FILES_${PN}-extension-dri2 = "${libdir}/xorg/modules/extensions/libdri2.so"
FILES_${PN}-extension-glx = "${libdir}/xorg/modules/extensions/libglx.so"
FILES_${PN}-module-libint10 = "${libdir}/xorg/modules/libint10.so"
FILES_${PN}-module-libafb = "${libdir}/xorg/modules/libafb.so"
FILES_${PN}-module-libwfb = "${libdir}/xorg/modules/libwfb.so"
FILES_${PN}-module-libmfb = "${libdir}/xorg/modules/libmfb.so"
FILES_${PN}-module-libcfb = "${libdir}/xorg/modules/libcfb.so"
FILES_${PN}-module-xaa = "${libdir}/xorg/modules/libxaa.so"
FILES_${PN}-module-libxf1bpp = "${libdir}/xorg/modules/libxf1bpp.so"
FILES_${PN}-module-libxf4bpp = "${libdir}/xorg/modules/libxf4bpp.so"

PACKAGES =+ "${PN}-multimedia-modules"

FILES_${PN}-multimedia-modules = "${libdir}/xorg/modules/multimedia/*drv*"

do_stage() {
	autotools_stage_all
}

do_install_append () {
	ln -sf ${datadir}/fonts/X11 ${D}/${libdir}/X11/fonts
}
