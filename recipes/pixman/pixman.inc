SECTION = "libs"
PRIORITY = "optional"
DESCRIPTION = "Low-level pixel manipulation library."
LICENSE = "X11"

BBCLASSEXTEND = "native"

#DEPENDS = "perl-native"

SRC_URI = "http://cairographics.org/releases/${BPN}-${PV}.tar.gz"

INC_PR ?= ""
PR = "r1${INC_PR}"

inherit autotools pkgconfig

DEPENDS += "${HOST_ARCH}/sysroot-libm"
