# Misc build failure for master HEAD
SRC_URI += "file://crosscompile.patch \
            file://fix_open_max_preprocessor_error.patch \
            file://mips64-compiler.patch \
            file://aarch64.patch \
            file://fix_compilation_when_not_using_xinerama.patch \
            file://0001-dixstruct.h-fix-segfaults-char-is-unsigned-for-ARM-a.patch \
           "
