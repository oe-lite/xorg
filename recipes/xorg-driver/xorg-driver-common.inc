DESCRIPTION = "X driver"
HOMEPAGE = "http://www.x.org"
BUGTRACKER = "https://bugs.freedesktop.org"
SECTION = "x11/drivers"
LICENSE = "MIT-X"

INC_PR = "r0"

DEPENDS = "xorg-server${RE}-dev xproto${RE}-dev randrproto${RE}-dev \
	util-macros${RE}-dev pixman${RE}-dev inputproto${RE}-dev \
	libpciaccess${RE}-dev \
	"

SRC_URI = "${XORG_MIRROR}/individual/driver/${BPN}-${PV}.tar.bz2"

FILES_${PN} += "${libdir}/xorg/modules/drivers/*.so"
FILES_${PN}-dbg += "${libdir}/xorg/modules/drivers/.debug"
FILES_${PN}-dev += "${libdir}/xorg/modules/drivers/*.a ${libdir}/xorg/modules/drivers/*.la"

inherit autotools pkgconfig

# AC_CHECK_FILE doesn't work when cross compiling, so we create a replacement
# macro that simply assumes the test succeeds. 
do_configure_prepend () {
    echo 'AC_DEFUN(CC_AC_CHECK_FILE, $2)' > configure.ac.new
    sed 's/AC_CHECK_FILE/CC_AC_CHECK_FILE/g' configure.ac >> configure.ac.new
    mv configure.ac.new configure.ac
}

MACHINE_CPPFLAGS += "-I${MACHINE_SYSROOT}${includedir}/xorg -I${MACHINE_SYSROOT}${includedir}/pixman-1"

#do_configure_prepend() {
#	incdir=${layout_includedir}/xorg
#	for f in dri.h sarea.h dristruct.h exa.h damage.h xf86Module.h; do
#		path="$incdir/$f"
#		if [ -f "${STAGING_DIR_HOST}/$path" ]; then
#			p=`echo "$path" | sed 'y%*+%pp%;s%[^_[:alnum:]]%_%g'`
#			eval "export ac_cv_file_$p=yes"
#		fi
#	done
#}

## FIXME: We don't want to include the libtool archives (*.la) from modules
## directory, as they serve no useful purpose. Upstream should fix Makefile.am
#do_install_append() {
#	find ${D}${libdir}/xorg/modules -regex ".*\.la$" | xargs rm -f --
#}
