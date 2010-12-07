require xorg-xserver-common.inc

DESCRIPTION = "the X.Org X server"
DEPENDS += "pixman${RE}-dev libpciaccess${RE}-dev openssl${RE}-dev dri2proto${RE}-dev glproto${RE}-dev"
PR = "${INC_PR}.1"

RDEPENDS_${PN} += "libpciaccess pixman \
	${HOST_ARCH}/sysroot-libdl ${HOST_ARCH}/sysroot-libm \
	"

SRC_URI += "file://sysroot_fix.patch;patch=1 \
            file://dolt-fix-1.7.0.patch;patch=1 \
            file://randr-support-1.7.0.patch;patch=1 \
	    file://hack-fbdev-ignore-return-mode.patch;patch=1 \
           "

SRC_URI_append_nitrogen-e = " file://xorg-server-disable-lcd-auto-blank.patch;patch=1 \
			  file://hack-assume-pixman-supports-overlapped-blt.patch;patch=1 \
			  "

do_install_prepend() {
        mkdir -p ${D}/${libdir}/X11/fonts
}

EXTRA_OECONF += " --disable-kdrive --disable-xephyr --disable-xsdl --disable-xfake --disable-xfbdev --disable-dmx"
EXTRA_OECONF += " --disable-glx-tls --enable-dri2 --disable-unit-tests "

export LDFLAGS += " -ldl "
