#This is a development snapshot, so lets hint OE to use the releases
DEFAULT_PREFERENCE = "-1"
DEFAULT_PREFERENCE_angstrom = "1"

SECTION = "libs"
PRIORITY = "optional"
DEPENDS = "pixman${RE}-dev libX11${RE}-dev libsm${RE}-dev libpng${RE}-dev fontconfig${RE}-dev libxrender${RE}-dev"
DESCRIPTION = "Cairo graphics library"
LICENSE = "MPL LGPL"

SRCREV = "e649754077f4364e96669c2de4791bfd0054f1fd"

PV = "1.9.14"

SRC_URI = "git://git.cairographics.org/git/cairo;protocol=git \
	  "
inherit autotools pkgconfig

S = "${WORKDIR}/git"

do_compile_append() {
	cd ${S}/perf ; oe_runmake
}

do_stage () {
 	autotools_stage_all
}
