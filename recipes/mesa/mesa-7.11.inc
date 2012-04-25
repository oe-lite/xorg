DEPENDS += "native:mesa-dri-glsl"


SRC_URI = "ftp://ftp.freedesktop.org/pub/mesa/${PV}/MesaLib-${PV}.tar.bz2 \
           file://uclibc.patch \
           file://crossfix.patch \
           file://crossfix-mklib.patch \
           file://mesa_fix_for_x32.patch \
           "
S = "${SRCDIR}/Mesa-${PV}"

do_autoreconf[prefuncs] += "do_autoreconf_fixup"
do_autoreconf_fixup() {
  #check for python not python2, because python-native does not stage python2 binary/link
  sed -i 's/AC_CHECK_PROGS(\[PYTHON2\], \[python2 python\])/AC_CHECK_PROGS(\[PYTHON2\], \[python python\])/g' ${S}/configure.ac
  # We need builtin_compiler built for buildhost arch instead of target (is provided by mesa-dri-glsl-native)"
  sed -i "s#\./builtin_compiler#builtin_compiler#g" ${S}/src/glsl/Makefile
}
