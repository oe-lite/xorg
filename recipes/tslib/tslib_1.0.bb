SRC_URI = "http://download.berlios.de/${BPN}/${BP}.tar.bz2 \
           file://fix_version.patch \
           file://tslib-nopressure.patch \
           file://tslib-pluginsld.patch \
           file://newer-libtool-fix.patch "
PR = "${INC_PR}.0"

include tslib.inc
do_configure_prepend () {
        ./autogen.sh
}
