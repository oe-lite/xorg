require xorg-lib-common.inc

DESCRIPTION = "Base X libs."
COMMON_DEPENDS = "util-macros${RE} util-macros${RE}-dev xtrans${RE}-dev libXdmcp${RE}-dev \
libXau${RE}-dev \
bigreqsproto${RE}-dev xproto${RE}-dev xextproto${RE}-dev xcmiscproto${RE}-dev \
xf86bigfontproto${RE}-dev kbproto${RE}-dev inputproto${RE}-dev \
xproto-native-dev \
"

DEPENDS = "libxcb${RE}-dev ${COMMON_DEPENDS}"		  
DEPENDS_virtclass-native = "${COMMON_DEPENDS}"
DEPENDS_virtclass-nativesdk = "${COMMON_DEPENDS}"
AUTOTOOLS_AUTORECONF = 1
acpaths = " -Im4/ -I${TARGET_SYSROOT}${datadir}/aclocal"


#-I /data/staff/home/mts/customers/oe-lite/tmp.d/default/work/machine/arm-cortexa8-linux-gnueabi/libX11-1.3.6-r0.0/libX11-1.3.6/m4/ -I /data/staff/home/mts/customers/oe-lite/tmp.d/default/work/machine/arm-cortexa8-linux-gnueabi/libX11-1.3.6-r0.0/stage/sysroot/usr/share/aclocal/


BBCLASSEXTEND = "native sdk"
PE = "1"

PACKAGES =+ "${PN}-xcb"

FILES_${PN} += "${datadir}/X11/XKeysymDB ${datadir}/X11/XErrorDB ${libdir}/X11/Xcms.txt"
FILES_${PN}-xcb += "${libdir}/libX11-xcb.so.*"
FILES_${PN}-locale += "${datadir}/X11/locale ${libdir}/X11/locale"

EXTRA_OECONF += " --with-xcb  \
--with-groff=no --with-ps2pdf=no --with-fop=no \
"
EXTRA_OECONF_native = " --without-xcb --with-groff=no --with-ps2pdf=no \
--with-fop=no \
"
EXTRA_OECONF_sdk = " --without-xcb --with-groff=no --with-ps2pdf=no \
--with-fop=no \
"

# Below option is added to overcome the GCC bug on ARM
# see http://gcc.gnu.org/PR42981 for further details.
# We could potentially take it off when its fixed in gcc 4.5

CFLAGS_append_arm = " -fforward-propagate "

SRC_URI += " \
             file://x11_disable_makekeys.patch;patch=1 \
"

do_compile_prepend() {
	(
		unset CC LD CXX CCLD CFLAGS CPPFLAGS LDFLAGS CXXFLAGS
		cd src/util; 
		mv makekeys.c.orig makekeys.c || true
		# MIN_REHASH 10 is only in 1.0.1
		sed -i -e 's:MIN_REHASH 10:MIN_REHASH 16:g' makekeys.c
		sed -i -e 's:MIN_REHASH 15:MIN_REHASH 16:g' makekeys.c
		touch makekeys-makekeys.o ; ${BUILD_CC} ${BUILD_CFLAGS} makekeys.c -o makekeys
		# mv to stop it getting rebuilt
		mv makekeys.c makekeys.c.orig
		cd ../../
	) || exit 1
}
