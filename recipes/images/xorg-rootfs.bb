RDEPENDS = "\
busybox \
xorg-server \
xorg-server-fbdev \
initramfs-init \
ssh scp \
xf86-input-evdev \
xf86-input-keyboard \
xf86-input-mouse \
xf86-input-tslib \
xf86-video-imx \
libz160 \
firmware-imx \
imx-lib \
imx-test \
amd-gpu-x11-bin-mx51 \
"

inherit cpio-image
inherit tar-image
