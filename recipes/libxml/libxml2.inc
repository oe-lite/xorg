DESCRIPTION = "GNOME XML Parser library"
SECTION = "libs"
PRIORITY = "optional"
LICENSE = "MIT"
INC_PR = "r0"

SRC_URI = "ftp://xmlsoft.org/${BPN}/${BPN}-${PV}.tar.gz"

DEPENDS = "${HOST_ARCH}/sysroot-libdl ${HOST_ARCH}/sysroot-libm"

BBCLASSEXTEND = "native"

inherit autotools pkgconfig binconfig

EXTRA_OECONF = "\
 --without-legacy \
 --with-catalog \
 --with-docbook \
 --with-c14n"

EXTRA_OECONF += "--without-python"
EXTRA_OECONF_native += " --with-python"

export LDFLAGS += "-ldl"

# do_install_append() {
# 	install -d ${D}${datadir}/aclocal
# 	install -m 0644 libxml.m4 ${D}${datadir}/aclocal

# 	#this is need it by php during its install
# 	install -d ${STAGING_BINDIR_CROSS}
# 	install -m 0755 xml2-config ${STAGING_BINDIR_CROSS}/
# }

# do_install_append_virtclass-native() {
# 	:
# }

PACKAGES =+ "${PN}-utils"
FILES_${PN} = "${libexecdir}/* ${libdir}/lib*${SOLIBS} \
            ${sysconfdir} ${sharedstatedir} ${localstatedir} \
            ${base_libdir}/*${SOLIBS} \
            ${datadir}/${PN} ${libdir}/${PN}/* \
            ${datadir}/pixmaps ${datadir}/applications \
            ${datadir}/idl ${datadir}/omf ${datadir}/sounds \
            ${libdir}/bonobo/servers"

FILES_${PN}-utils = "${bindir}/xmllint ${bindir}/xmlcatalog ${libdir}/*.sh"
FILES_${PN}-doc += "${datadir}/gtk-doc"