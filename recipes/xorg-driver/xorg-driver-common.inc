DESCRIPTION = "X driver"
HOMEPAGE = "http://www.x.org"
BUGTRACKER = "https://bugs.freedesktop.org"
LICENSE = "MIT-X"

require conf/fetch/xorg.conf

DEPENDS = "xserver-xorg xproto randrproto util-macros"
SRC_URI = "${XORG_MIRROR}/individual/driver/${PN}-${PV}.tar.bz2"

S = "${SRCDIR}/${PN}-${PV}"

FILES_${PN} += " ${libdir}/xorg/modules/drivers/*.so"
FILES_${PN}-dbg += " ${libdir}/xorg/modules/drivers/.debug"

inherit autotools-autoreconf pkgconfig

#hack for includes
CFLAGS += " -I${HOST_SYSROOT}${includedir}/xorg \
            -I${HOST_SYSROOT}${includedir}/pixman-1 \
            -I${HOST_SYSROOT}${includedir}"

# AC_CHECK_FILE doesn't work when cross compiling, so we create a replacement
# macro that simply assumes the test succeeds. 
do_configure[prefuncs] += "do_configure_input"
do_configure_input () {
    echo 'AC_DEFUN(CC_AC_CHECK_FILE, $2)' > configure.ac.new
    sed 's/AC_CHECK_FILE/CC_AC_CHECK_FILE/g' configure.ac >> configure.ac.new
    mv configure.ac.new configure.ac
}

# FIXME: We don't want to include the libtool archives (*.la) from modules
# directory, as they serve no useful purpose. Upstream should fix Makefile.am
do_install[postfuncs] += "do_install_input"
do_install_input() {
	find ${D}${libdir}/xorg/modules -regex ".*\.la$" | xargs rm -f --
}
