DESCRIPTION = "Platform specific unit tests for the i.MX51 platform"
LICENSE = "GPL"
HOMEPAGE = "http://www.freescale.com/"
PR = "r1"

DEPENDS = "kernel"

COMPATIBLE_CPU = "arm-imx51"
PACKAGE_ARCH = "${MACHINE_ARCH}"

SRC_URI = "file://${BPN}-${PV}.tar.gz \
           file://OE_cross_compile.patch;patch=1 \
          "

S = "${WORKDIR}/imx-test-10.07.11/"

# fixes the missing GNU_HASH errors in package_qa
TARGET_CC_ARCH += " ${LDFLAGS}"

do_compile() {
	KERNELDIR=`cat ${STAGING_DIR}/${MACHINE_ARCH}${TARGET_VENDOR}-${TARGET_OS}/kernel/kernel-source`
	INCLUDE="-I${KERNELDIR}/include -I${KERNELDIR}/drivers/mxc/security/rng/include \
                 -I${KERNELDIR}/drivers/mxc/security/sahara2/include"

	# build test apps
	oe_runmake -j1 PLATFORM=IMX51 INCLUDE="${INCLUDE}" test

	# build modules
	export LDFLAGS=`echo $LDFLAGS|sed -e "s/-Wl,//g"|sed -e "s/,/ /g"`
	oe_runmake -C module_test KBUILD_OUTPUT=${KERNELDIR} LINUXPATH=${KERNELDIR} CROSS_COMPILE=${CROSS_DIR}/bin/${HOST_PREFIX}
}

do_install() {
	KERNELDIR=`cat ${STAGING_DIR}/${MACHINE_ARCH}${TARGET_VENDOR}-${TARGET_OS}/kernel/kernel-source`
	install -d ${D}
	install -d ${D}/unit_tests

	# install test apps
	oe_runmake PLATFORM=IMX51 DESTDIR=${D}/unit_tests install

	# install modules
	oe_runmake -C module_test -j1 KBUILD_OUTPUT=${KERNELDIR} LINUXPATH=${KERNELDIR} INSTALL_MOD_PATH=${D} install

}

PACKAGES = "${PN} ${PN}-dbg"

FILES_${PN} = "/unit_tests/* /lib/modules/2.6.*/test/*"
FILES_${PN}-dbg = "/unit_tests/.debug/*"
