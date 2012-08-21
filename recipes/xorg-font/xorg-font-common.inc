HOMEPAGE = "http://www.x.org"
BUGTRACKER = "https://bugs.freedesktop.org/enter_bug.cgi?product=xorg"

LICENSE = "MIT-X"

require conf/fetch/xorg.conf

DEPENDS = " encodings font-alias native:font-util native:mkfontdir native:mkfontscale"
RDEPENDS_${PN} = "encodings font-util font-alias"

XORG_PN = "${PN}"

SRC_URI = "${XORG_MIRROR}/individual/font/${XORG_PN}-${PV}.tar.bz2"
S = "${SRCDIR}/${XORG_PN}-${PV}"

inherit autotools pkgconfig

EXTRA_OEMAKE += "FCCACHE=/bin/true"

do_configure[prefuncs] += "do_configure_xorg_fonts"
do_configure_xorg_fonts() {
        if [ -f "${S}"/configure.ac ] ; then
                sed -i "s#^MAPFILES_PATH=.*#MAPFILES_PATH=\"${STAGE_DIR}/\$(pkg-config --variable=mapdir fontutil)\"#g" "${S}"/configure.ac
        fi
}

do_install[postfuncs] += "do_install_xorg_fonts"
do_install_xorg_fonts() {
	find ${D}${libdir}/X11/fonts -type f -name fonts.dir | xargs rm -f
	find ${D}${libdir}/X11/fonts -type f -name fonts.scale | xargs rm -f
	find ${D}${datadir}/fonts/X11 -type f -name fonts.dir | xargs rm -f
	find ${D}${datadir}/fonts/X11 -type f -name fonts.scale | xargs rm -f	
}

FILES_${PN} += " ${libdir}/X11/fonts ${datadir}"

pkg_postinst_${PN} () {
        set -x
        for fontdir in `find $D/usr/lib/X11/fonts -type d`; do
                mkfontdir $fontdir
                mkfontscale $fontdir
        done
        for fontdir in `find $D/usr/share/fonts/X11 -type d`; do
                mkfontdir $fontdir
                mkfontscale $fontdir
        done
}
