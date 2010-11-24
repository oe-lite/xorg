require xorg-lib-common.inc
DESCRIPTION = "X Display Manager Control Protocol library"
DEPENDS += "xproto-dev"
PE = "1"
PR = "${INC_PR}.0"
BBCLASSEXTEND = "native sdk"
