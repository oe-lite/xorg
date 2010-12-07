DESCRIPTION = "Firmware for i.MX platform"
LICENSE = "Freescale EULA"
HOMEPAGE = "http://www.freescale.com/"
PR = "r0"

PACKAGE_ARCH = "${MACHINE_ARCH}"

SRC_URI = "http://repository.timesys.com/buildsources/${BPN:0:1}/${BPN}/${BPN}-${PV}/${BPN}-${PV}.tar.gz"

do_install() {
	install -d ${D}/lib/firmware
	cp -rf ${S}/firmware/* ${D}/lib/firmware
	install -d ${D}/usr/share/doc/linux-firmware/licenses
	cp -rf ${S}/licenses/* ${D}/usr/share/doc/linux-firmware/licenses
}

PACKAGES += "${PN}-notapplicable"

FILES_${PN} += "/lib/firmware/*"
FILES_${PN} += "/lib/firmware/vpu/*"
FILES_${PN}-notapplicable += "/lib/firmware/ath6k/*"
FILES_${PN}-notapplicable += "/lib/firmware/ath6k/AR6102/*"
FILES_${PN}-notapplicable += "/lib/firmware/ath6k/AR6003/*"
FILES_${PN}-notapplicable += "/lib/firmware/ath6k/AR6003/hw2.0/*"
FILES_${PN}-notapplicable += "/lib/firmware/ath6k/AR6003/hw1.0/*"
FILES_${PN}-notapplicable += "/usr/share/doc/linux-firmware/licenses/ath6k/AR6102/*"
FILES_${PN}-notapplicable += "/usr/share/doc/linux-firmware/licenses/ath6k/AR6003/*"
