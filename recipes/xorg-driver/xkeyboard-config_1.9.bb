DESCRIPTION = "Keyboard configuration database for X Window"
HOMEPAGE = "http://freedesktop.org/wiki/Software/XKeyboardConfig"
BUGTRACKER = "https://bugs.freedesktop.org/enter_bug.cgi?product=xkeyboard-config"
LICENSE = "MIT & MIT-style"

SRC_URI = "${XORG_MIRROR}/individual/data/${BPN}/${BPN}-${PV}.tar.bz2"
#DEPENDS = "intltool xkbcomp-native glib-2.0"
DEPENDS = "xkbcomp-native"

PR = "r0"

EXTRA_OECONF = "--with-xkb-rules-symlink=xorg"

RDEPENDS_${PN} += "xkbcomp"
FILES_${PN} += "${datadir}/X11/xkb"

inherit autotools pkgconfig

do_install_append () {
    install -d ${D}/usr/share/X11/xkb/compiled
    cd ${D}${datadir}/X11/xkb/rules && ln -sf base xorg
}
