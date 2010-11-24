require xorg-font-common.inc

PACKAGE_ARCH = "${BASE_PACKAGE_ARCH}"

DESCRIPTION = "X font utils."

DEPENDS = "util-macros${RE}-dev"
RDEPENDS_${PN} = "mkfontdir mkfontscale encodings"
BBCLASSEXTEND = "native"

PE = "1"
PR = "${INC_PR}.0"

# oe-lite
#do_configure_prepend() {
#        sed -i "s#MAPFILES_PATH=\`pkg-config#MAPFILES_PATH=\`PKG_CONFIG_PATH=\"${STAGING_LIBDIR_NATIVE}/pkg-config\" pkg-config#g" fontutil.m4.in
#}
