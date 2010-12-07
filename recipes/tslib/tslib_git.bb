SRC_URI = "git://github.com/kergoth/tslib.git;protocol=git"
S = "${WORKDIR}/git"
SRCREV = "5243db505b109df3001f"
PV = "1.0+gitr${SRCPV}"
PR = "${INC_PR}.3"

DEFAULT_PREFERENCE = "-1"

include tslib.inc
