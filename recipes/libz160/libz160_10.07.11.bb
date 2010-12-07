DESCRIPTION = "Z160 2D driver"
LICENSE = "Proprietary"
VENDOR = "Freescale"
PR = "r1"

COMPATIBLE_MACHINE = "sbc-imx51"
PACKAGE_ARCH = "${MACHINE_ARCH}"

SRC_URI = "http://support.bluetechnix.at/permanent/imx-linux-packages/libz160-bin-10.07.11.tar.gz"

S = "${WORKDIR}/libz160-bin-10.07.11/"

# don't care about missing GNU_HASHes in the binaries
INSANE_SKIP_${PN} = True

do_install() {
	install -d ${D}/usr/lib/
	cp -rpP usr/lib/* ${D}/usr/lib
}

do_stage() {
	install -d ${D}/usr/include/
	cp -rpP usr/include/* ${STAGING_INCDIR}
	cp -rpP usr/lib/* ${STAGING_LIBDIR}
}

SRC_URI[md5sum] = "1f5863d3dcf0aa8c6ece7befb66dd83c"
SRC_URI[sha256sum] = "0b900ae6d9079fbf24a6f756dc58d9521087a8fa6f0e6c6ca93381b355ec2bd6"

FILES_${PN} = "/usr/lib/*"
