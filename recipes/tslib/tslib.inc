DESCRIPTION = "tslib is a plugin-based flexible touchscreen access library."
HOMEPAGE = "http://tslib.berlios.de/"
AUTHOR = "Russell King w/ plugins by Chris Larson et. al."
SECTION = "base"
LICENSE = "LGPLv2"
INC_PR = "r0"

SRC_URI += "\
  file://ts.conf \
  file://tslib.sh \
"

inherit autotools pkgconfig

EXTRA_OECONF += "--enable-shared ac_cv_func_malloc_0_nonnull=yes"

do_install_append () {
	install -d ${D}${sysconfdir}/profile.d/
	install -m 0755 ${WORKDIR}/tslib.sh ${D}${sysconfdir}/profile.d/
	install -m 0644 ${WORKDIR}/ts.conf ${D}${sysconfdir}/ts.conf
}

PACKAGES =+ "${BPN}-conf ${BPN}-tests ${BPN}-calibrate"
DEPENDS += "${HOST_ARCH}/sysroot-libdl"

RDEPENDS_${PN} = "${BPN}"

FILES_${PN}-dbg += "${libdir}/ts/.debug*"
FILES_${PN}-conf = "${sysconfdir}/ts.conf ${sysconfdir}/profile.d/tslib.sh ${datadir}/tslib"
FILES_${PN} = "${libdir}/*${SOLIBS} ${libdir}/ts/*.so"
FILES_${PN}-dev += "${libdir}/ts/*.la ${libdir}/ts/*.a"
FILES_${PN}-calibrate = "${bindir}/ts_calibrate"
FILES_${PN}-tests = "${bindir}/ts_harvest ${bindir}/ts_print ${bindir}/ts_print_raw ${bindir}/ts_test"
