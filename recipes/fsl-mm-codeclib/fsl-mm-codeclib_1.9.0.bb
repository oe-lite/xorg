DESCRIPTION = "Freescale Multimedia core libraries"
LICENSE = "Freescale Proprietary"
HOMEPAGE = "http://www.freescale.com/"
PR = "r1"

COMPATIBLE_CPU = "arm-imx51"
PACKAGE_ARCH = "${MACHINE_ARCH}"

SRC_URI = "http://repository.timesys.com/buildsources/f/${BPN}/${BPN}-${PV}/${BPN}-${PV}.tar.gz"

# don't care about missing GNU_HASHes in the binaries
INSANE_SKIP_${PN} = True
INSANE_SKIP_${PN}-dev = True

do_install() {
	install -d ${D}${libdir}
	find ${S}/release/lib/ -name "*arm9*.so" | xargs -I corelib install -m 0755 corelib ${D}${libdir}
	find ${S}/release/lib/ -name "*arm11*.so" | xargs -I corelib install -m 0755 corelib ${D}${libdir}
	find ${S}/release/lib/ -name "*arm12*.so" | xargs -I corelib install -m 0755 corelib ${D}${libdir}
	install -d ${D}${bindir}
	find ${S}/release/exe/ -name "*test_*" | xargs -I corelib install -m 0755 corelib ${D}${bindir}

	find ${D}${libdir} -name "*arm9*.*" | xargs rm -f
	find ${D}${libdir} -name "lib_H264_dec_arm11_elinux.so" | xargs rm -f
	find ${D}${libdir} -name "lib_mpeg2_dec_arm11_elinux.so" | xargs rm -f
	find ${D}${libdir} -name "lib_MPEG4_dec_arm11_elinux.so" | xargs rm -f
	find ${D}${libdir} -name "lib_MPEG4ASP_dec_arm11_elinux.so" | xargs rm -f
	find ${D}${libdir} -name "lib_WMV9MP_dec_MP_arm11_elinux.so" | xargs rm -f
	find ${D}${libdir} -name "lib_wma10_dec_arm11_elinux.so" | xargs rm -f
	find ${D}${libdir} -name "lib_mp3_dec_arm11_elinux.so" | xargs rm -f
	find ${D}${libdir} -name "lib_aac_dec_arm11_elinux.so" | xargs rm -f
	find ${D}${libdir} -name "libmpeg4_encoder_arm11_ELINUX.so" | xargs rm -f
	find ${D}${libdir} -name "lib_mp3_enc_arm11_elinux.so" | xargs rm -f
	find ${D}${bindir} -name "test*arm9*.*" | xargs rm -f

	find ${S}/release/lib/ -name "lib_nb_amr_*_arm9_elinux.so" | xargs -I corelib install -m 0755 corelib ${D}${libdir}
	find ${S}/release/lib/ -name "lib_g.729ab_*_arm9_elinux.so" | xargs -I corelib install -m 0755 corelib ${D}${libdir}
	find ${S}/release/lib/ -name "lib_g.723.1_*_arm9_elinux.so" | xargs -I corelib install -m 0755 corelib ${D}${libdir}

	find ${S}/release/exe/ -name "test_nb_amr_*_arm9_elinux" | xargs -I corelib install -m 0755 corelib ${D}${bindir}
	find ${S}/release/exe/ -name "test_g.729ab_*_arm9_elinux" | xargs -I corelib install -m 0755 corelib ${D}${bindir}
	find ${S}/release/exe/ -name "test_g.723.1_*_arm9_elinux" | xargs -I corelib install -m 0755 corelib ${D}${bindir}
}

do_stage () {
	# we need that for gst-fsl-plugin
	install -d ${STAGING_INCDIR}/mm_ghdr
	cp -r ${S}/ghdr/* ${STAGING_INCDIR}/mm_ghdr

	# we need that for gst-fsl-plugin
	install -d ${STAGING_LIBDIR}
	cp -r ${D}${libdir}/* ${STAGING_LIBDIR}

	install -d ${STAGING_LIBDIR}/pkgconfig
	cp -r ${S}/pkgconfig/*.pc ${STAGING_LIBDIR}/pkgconfig/
}

FILES_${PN} += "${libdir}/*"
