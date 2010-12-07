require xf86-input-common.inc
DESCRIPTION = "X.Org X server -- tslib input driver"
DEPENDS += "tslib${RE}-dev tslib${RE} ${HOST_ARCH}/sysroot-libdl renderproto${RE}-dev"
RDEPENDS_${PN} += "tslib-calibrate tslib"

PR = "${INC_PR}.0"

SRC_URI = "http://www.pengutronix.de/software/xf86-input-tslib/download/${BPN}-${PV}.tar.bz2 \
           file://double-free-crash.patch;patch=1 \                                                                                                                                                                                            
           file://10-x11-input-tslib.fdi \                                                                                                                                                                                                     
           file://xserver-174-XGetPointerControl.patch;patch=1 \                                                                                                                                                                               
           file://99-xf86-input-tslib.rules \                                                                                                                                                                                                  
"                                                                                                                                                                                                                                              
 
do_configure_prepend() {
        rm -rf ${S}/m4/ || true
}

do_install_append() {
#        install -d ${D}/${datadir}/hal/fdi/policy/20thirdparty
#        install -m 0644 ${WORKDIR}/10-x11-input-tslib.fdi ${D}/${datadir}/hal/fdi/policy/20thirdparty
#        install -d ${D}/lib/udev/rules.d
#        install -m 0644 ${WORKDIR}/99-xf86-input-tslib.rules ${D}/lib/udev/rules.d/
}

#FILES_${PN} += "${datadir}/hal /lib/udev"
