DESCRIPTION = "Platform specific libraries for the i.MX platform"
LICENSE = "LGPL"
HOMEPAGE = "http://www.freescale.com/"
PR = "r1"

inherit autotools

#DEPENDS = "virtual/kernel"

COMPATIBLE_CPU = "arm-imx51"
PACKAGE_ARCH = "${MACHINE_ARCH}"

SRC_URI = " \
           http://repository.timesys.com/buildsources/${BPN:0:1}/${BPN}/${BPN}-${PV}/${BPN}-${PV}.tar.gz \
           file://OE_cross_compile2.patch;patch=1 \
          "

# fixes the missing GNU_HASH errors in package_qa
TARGET_CC_ARCH += " ${LDFLAGS}" 

do_compile() {
	KERNELDIR=`cat ${STAGING_DIR}/${MACHINE_ARCH}${TARGET_VENDOR}-${TARGET_OS}/kernel/kernel-source`
	INCLUDE="-I${KERNELDIR}/include -I${KERNELDIR}/drivers/mxc/security/rng/include \
                 -I${KERNELDIR}/drivers/mxc/security/sahara2/include \
		 -I${S}/ipu"
	oe_runmake PLATFORM=IMX51 INCLUDE="${INCLUDE}"
}

do_install() {
	install -d ${D}
	oe_runmake PLATFORM=IMX51 DEST_DIR=${D} install
}

do_stage() {
	install -d ${STAGING_INCDIR}
	install -m 0644 ${D}/usr/include/*.h ${STAGING_INCDIR}
	install -d ${STAGING_LIBDIR}
	install -m 0755 ${D}/usr/lib/*.so ${STAGING_LIBDIR}
}

FILES_${PN} += "${libdir}/*.so"
