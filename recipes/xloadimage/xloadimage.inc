DESCRIPTION = "An utility to view many different types of images under X11"
LICENSE = "MIT"

SRC_URI = "http://http.debian.net/debian/pool/main/x/xloadimage/${PN}_${PV}.orig.tar.gz \
	file://01_libjpeg-support.patch \
	file://02_png-support.patch \
	file://03_security-strfoo.patch \
	file://04_previous-image.patch \
	file://05_idelay-manpage.patch \
	file://06_-Wall-cleanup.patch \
	file://07_SYSPATHFILE.patch \
	file://08_manpage-config-path.patch \
	file://09_xloadimagerc-path.patch \
	file://10_config.c-HOME-fix.patch \
	file://11_fork-implies-quiet.patch \
	file://12_fix-tile.patch \
	file://13_varargs-is-obsolete.patch \
	file://14_errno-not-extern.patch \
	file://15_CAN-2005-0638.patch \
	file://16_CAN-2005-0639.patch \
	file://17_security-sprintf.patch \
	file://18_manpage_fixes.patch \
	file://19_fix_root_c_resource_leak.patch \
	file://20_patch.patch \
	file://21_libpng.patch \
	file://22-include.patch \
	file://23_jpeg.c-build-fix.patch \
	file://25_hardening-flags.patch \
	file://26_uufilter-implicit-declaration.patch \
	file://27_shrink-should-not-zoom-upwards.patch \
	file://28_correct-scaling-fullscreen.patch \
	file://29_fix-manpage-hyphens.patch \
	file://30_libtiff5.patch \
	file://libdl-configure.patch"

inherit autotools

DEPENDS = "xproto xproto-dev libx11 libx11-dev libpng libpng-dev libm libdl"
DEPENDS_${PN} = "xproto libx11 libpng libm libdl"

do_configure[prefuncs] += "do_configure_removemake"
do_configure_removemake() {
	rm -fr ${S}/Makefile
	chmod +x ${S}/configure
}

do_install () {
	install -m 0755 -d ${D}${bindir}
	install -m 0755 xloadimage ${D}${bindir}
}

S = "${SRCDIR}/xloadimage.${PV}"
