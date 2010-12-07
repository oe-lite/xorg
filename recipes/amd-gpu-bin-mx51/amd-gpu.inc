DESCRIPTION = "GPU driver and app for mx51"
LICENSE = "Proprietary"
VENDOR = "AMD"

COMPATIBLE_CPU = "arm-imx51"
PACKAGE_ARCH = "${MACHINE_ARCH}"

SRC_URI = "http://repository.timesys.com/buildsources/${BPN:0:1}/${BPN}/${BPN}-${PV}/${BPN}-${PV}.tar.gz"

# There are no GNU_HASHes in the binaries, and we cannot do anything about it
INSANE_SKIP_${PN} = True

do_install() {
	cp -rp * ${D}
}

FILES_${PN} = "/usr/lib/* \
               /usr/bin/* \
"

FILES_${PN}-dev = "/usr/include/GLES2/* \
                   /usr/include/EGL/* \
                   /usr/include/VG/* \
                   /usr/include/KHR/* \
                   /usr/include/GLES/* \
"
