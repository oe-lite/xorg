require xorg-driver-video.inc
PE = "1"

DESCRIPTION = "X.Org X server - i.MX accelerated video driver"
LICENSE = "X11"
VENDOR = "Freescale"
PR = "r0"

PACKAGE_ARCH = "${MACHINE_ARCH}"

DEPENDS += "libz160"

SRC_URI = " \
	http://support.bluetechnix.at/permanent/imx-linux-packages/xserver-xorg-video-imx-${PV}.tar.gz \
	file://autoreconf.patch;patch=1 \
	file://xorg-server-1.7.4-modifications-2.patch;patch=1 \
	file://exa-version.patch;patch=1 \
	file://dixlookupresource.patch;patch=1 \
"
SRC_URI[md5sum] = "e66781d37eda7ab669a1ad94a6eac33b"
SRC_URI[sha256sum] = "69c324d33c38baf50f8a9312d85784b6fee4cf1731ff70cc0f5958dddeb5728c"

S = "${WORKDIR}/xserver-xorg-video-imx-${PV}/"

do_install_append() {
	install -d ${D}/etc/X11
	cat <<EOF > ${D}/etc/X11/xorg.conf
Section "InputDevice"
        Identifier      "Generic Keyboard"
        Driver          "kbd"
        Option          "XkbRules"      "xorg"
        Option          "XkbModel"      "pc105"
        Option          "XkbLayout"     "us"
EndSection

Section "InputDevice"
        Identifier      "Configured Mouse"
        Driver          "mouse"
        Option          "CorePointer"
EndSection

Section "Device"
        Identifier      "i.MX Accelerated Framebuffer Device"
        Driver          "imx"
        Option          "ShadowFB"                      "false"
        Option          "MigrationHeuristic"            "smart"
EndSection

Section "Monitor"
        Identifier      "Configured Monitor"
EndSection

Section "Screen"
        Identifier      "Default Screen"
        Monitor         "Configured Monitor"
        Device          "Configured Video Device"
EndSection

Section "ServerLayout"
        Identifier      "Default Layout"
        Screen          "Default Screen"
EndSection

EOF
}

