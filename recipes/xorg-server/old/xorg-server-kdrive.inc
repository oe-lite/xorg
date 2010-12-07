HOMEPAGE = "http://www.x.org"
SECTION = "x11/base"
LICENSE = "MIT-X"

INC_PR = "r0"
inherit autotools pkgconfig

# No udev, hal and xsdl support
EXTRA_OECONF += " \
--disable-config-hal \
--disable-config-udev \
--disable-xsdl \
"

MACHINE_CPPFLAGS += "-I${MACHINE_SYSROOT}${includedir}/pixman-1"
 
# TODO: Use XORG_MIRROR
SRC_URI = "${XORG_MIRROR}/individual/xserver/xorg-server-${PV}.tar.bz2"
S = "${WORKDIR}/xorg-server-${PV}"

DEPENDS = " \
${HOST_ARCH}/sysroot-libdl \
${HOST_ARCH}/sysroot-libm \
bigreqsproto${RE}-dev \
calibrateproto${RE}-dev \
compositeproto${RE}-dev \
damageproto${RE}-dev \
dri2proto${RE}-dev \
fixesproto${RE}-dev \
flex-native \
fontsproto${RE}-dev \
freetype${RE}-dev \
glproto${RE}-dev \
inputproto${RE}-dev \
kbproto${RE}-dev \ 
libXau${RE}-dev \
libXdmcp${RE}-dev \
libXfont${RE} \
libXfont${RE}-dev \
libfontenc${RE} \
libfontenc${RE}-dev \
libpciaccess${RE}-dev \
libxkbfile${RE}-dev \
libxkbui${RE}-dev \
openssl${RE}-dev \
pixman${RE}-dev \
randrproto${RE}-dev \
recordproto${RE}-dev \
renderproto${RE}-dev \
resourceproto${RE}-dev \
scrnsaverproto${RE}-dev \
trapproto${RE}-dev \
tslib${RE}-dev \
util-macros${RE}-dev \
videoproto${RE}-dev \
xcmiscproto${RE}-dev \
xextproto${RE}-dev \
xf86dgaproto${RE}-dev \
xf86vidmodeproto${RE}-dev  \
xineramaproto${RE}-dev \
xproto${RE}-dev \
xtrans${RE}-dev \
zlib${RE} zlib${RE}-dev \
"

RDEPENDS_${PN} += "libpciaccess pixman libXfont libXau libXdmcp freetype zlib libfontenc \
	${HOST_ARCH}/sysroot-libdl ${HOST_ARCH}/sysroot-libm tslib\
	"

# Removed deps: fontconfig liblbxutil xf86driproto drm xf86miscproto xf86bigfontproto dmxproto evieext libfontenc
# libxxf86vm libxaw libxmu libxt libxpm libxext libx11
# libxxf86misc libxi libdmx libxtst libxres virtual/libgl libxcalibrate
# libxv ${DISTRO_XORG_CONFIG_MANAGER}"

#EXTRA_OECONF += " \
#--disable-dmx \
#--disable-dri \
#--disable-dri2 \
#--disable-glx \
#--disable-hal \
#--disable-ipv6 \
#--disable-kdrive \
#--disable-kdrive-vesa \
#--disable-libxf86config \
#--disable-nptl \
#--disable-record \
#--disable-tslib \
#--disable-unit-tests \
#--disable-xephyr \
#--disable-xfake \
#--disable-xfbdev \
#--disable-xfree86-utils \
#--disable-xnest \
#--disable-xorg  \
#--disable-xsdl \
#--enable-xcalibrate \
#ac_cv_file__usr_share_sgml_X11_defs_ent=no \
#"


EXTRA_OECONF += " \
--disable-acfb \
--disable-ccfb \
--disable-dga \
--disable-dmx \
--disable-dri \
--disable-dri2 \
--disable-glx \
--disable-ipv6 \
--disable-mcfb \
--disable-record \
--disable-static \
--disable-xf86misc \
--disable-xf86vidmode \
--disable-xinerama \
--disable-xkb \
--disable-xnest \
--disable-xorg \
--disable-xorgcfg \
--disable-xvfb \
--enable-composite \
--enable-kdrive \
--enable-tslib \
--localstatedir=/var \
--enable-xcalibrate \
--sysconfdir=/etc/X11 \
--with-fontdir=/usr/share/fonts/X11 \
--with-xkb-output=/var/lib/xkb \
ac_cv_file__usr_share_sgml_X11_defs_ent=no \
"

FILES_${PN}-dev += "${libdir}/xorg/modules/*.la ${libdir}/xorg/modules/*.a ${libdir}/xorg/modules/*/*.la ${libdir}/xorg/modules/*/*.a"
FILES_${PN}-utils = "${bindir}/scanpci ${bindir}/pcitweak ${bindir}/ioport ${bindir}/in[bwl] ${bindir}/out[bwl] ${bindir}/mmap[rw] ${bindir}/gtf ${bindir}/getconfig ${bindir}/getconfig.pl"
FILES_${PN} += "${libdir}/X11/Options ${libdir}/X11/Cards ${libdir}/X11/getconfig ${libdir}/X11/etc ${libdir}/xserver/SecurityPolicy ${libdir}/xorg/modules/*.so ${libdir}/xorg/modules/*/*.so ${libdir}/xorg/modules/*/*/*.so /etc/X11 "
FILES_${PN}-doc += "${libdir}/X11/doc /var/lib/xkb/README.compiled /usr/lib/xorg/protocol.txt"

FILES_${PN}-dbg += "${libdir}/xorg/modules/.debug \
                    ${libdir}/xorg/modules/*/.debug \
		    ${libdir}/xorg/modules/*/*/.debug \
		    "

#NOTE:   /usr/lib/xorg/protocol.txt
#NOTE:   /usr/lib/xorg/modules/libxaa.la
#NOTE:   /usr/lib/xorg/modules/libshadowfb.a
#NOTE:   /usr/lib/xorg/modules/libxaa.so
#NOTE:   /usr/lib/xorg/modules/libshadowfb.la
#NOTE:   /usr/lib/xorg/modules/libvgahw.a
#NOTE:   /usr/lib/xorg/modules/libexa.la
#NOTE:   /usr/lib/xorg/modules/libfb.so
#NOTE:   /usr/lib/xorg/modules/libvbe.la
#NOTE:   /usr/lib/xorg/modules/libfbdevhw.la
#NOTE:   /usr/lib/xorg/modules/libfbdevhw.so
#NOTE:   /usr/lib/xorg/modules/libfb.la
#NOTE:   /usr/lib/xorg/modules/libexa.so
#NOTE:   /usr/lib/xorg/modules/libint10.so
#NOTE:   /usr/lib/xorg/modules/libwfb.a
#NOTE:   /usr/lib/xorg/modules/libxaa.a
#NOTE:   /usr/lib/xorg/modules/libshadow.a
#NOTE:   /usr/lib/xorg/modules/libint10.la
#NOTE:   /usr/lib/xorg/modules/libvbe.a
#NOTE:   /usr/lib/xorg/modules/libwfb.la
#NOTE:   /usr/lib/xorg/modules/libvgahw.so
#NOTE:   /usr/lib/xorg/modules/libfb.a
#NOTE:   /usr/lib/xorg/modules/libvbe.so
#NOTE:   /usr/lib/xorg/modules/libshadowfb.so
#NOTE:   /usr/lib/xorg/modules/libfbdevhw.a
#NOTE:   /usr/lib/xorg/modules/libshadow.la
#NOTE:   /usr/lib/xorg/modules/libxf8_16bpp.la
#NOTE:   /usr/lib/xorg/modules/libint10.a
#NOTE:   /usr/lib/xorg/modules/libexa.a
#NOTE:   /usr/lib/xorg/modules/libxf8_16bpp.so
#NOTE:   /usr/lib/xorg/modules/libwfb.so
#NOTE:   /usr/lib/xorg/modules/libxf8_16bpp.a
#NOTE:   /usr/lib/xorg/modules/libshadow.so
#NOTE:   /usr/lib/xorg/modules/libvgahw.la
#NOTE:   /usr/lib/xorg/modules/extensions/libextmod.la
#NOTE:   /usr/lib/xorg/modules/extensions/libdbe.a
#NOTE:   /usr/lib/xorg/modules/extensions/libextmod.so
#NOTE:   /usr/lib/xorg/modules/extensions/libdbe.so
#NOTE:   /usr/lib/xorg/modules/extensions/libextmod.a
#NOTE:   /usr/lib/xorg/modules/extensions/libdbe.la
#NOTE:   /usr/lib/xorg/modules/extensions/.debug/libextmod.so
#NOTE:   /usr/lib/xorg/modules/extensions/.debug/libdbe.so
#NOTE:   /usr/lib/xorg/modules/.debug/libxaa.so
#NOTE:   /usr/lib/xorg/modules/.debug/libfb.so
#NOTE:   /usr/lib/xorg/modules/.debug/libfbdevhw.so
#NOTE:   /usr/lib/xorg/modules/.debug/libexa.so
#NOTE:   /usr/lib/xorg/modules/.debug/libint10.so
#NOTE:   /usr/lib/xorg/modules/.debug/libvgahw.so
#NOTE:   /usr/lib/xorg/modules/.debug/libvbe.so
#NOTE:   /usr/lib/xorg/modules/.debug/libshadowfb.so
#NOTE:   /usr/lib/xorg/modules/.debug/libxf8_16bpp.so
#NOTE:   /usr/lib/xorg/modules/.debug/libwfb.so
#NOTE:   /usr/lib/xorg/modules/.debug/libshadow.so
#NOTE:   /usr/lib/xorg/modules/multimedia/bt829_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/uda1380_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/uda1380_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/tda8425_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/tda9885_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/fi1236_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/tda9885_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/msp3430_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/tda9850_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/fi1236_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/fi1236_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/tda8425_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/uda1380_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/msp3430_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/tda9850_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/bt829_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/msp3430_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/bt829_drv.la
#NOTE:   /usr/lib/xorg/modules/multimedia/tda8425_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/tda9850_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/tda9885_drv.a
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/tda8425_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/tda9885_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/msp3430_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/fi1236_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/uda1380_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/tda9850_drv.so
#NOTE:   /usr/lib/xorg/modules/multimedia/.debug/bt829_drv.so##



#`configure' configures xorg-server 1.9.2 to adapt to many kinds of systems.
#
#Usage: ./configure [OPTION]... [VAR=VALUE]...
#
#To assign environment variables (e.g., CC, CFLAGS...), specify them as
#VAR=VALUE.  See below for descriptions of some of the useful variables.
#
#Defaults for the options are specified in brackets.
#
#Configuration:
#  -h, --help              display this help and exit
#      --help=short        display options specific to this package
#      --help=recursive    display the short help of all the included packages
#  -V, --version           display version information and exit
#  -q, --quiet, --silent   do not print `checking ...' messages
#      --cache-file=FILE   cache test results in FILE [disabled]
#  -C, --config-cache      alias for `--cache-file=config.cache'
#  -n, --no-create         do not create output files
#      --srcdir=DIR        find the sources in DIR [configure dir or `..']
#
#Installation directories:
#  --prefix=PREFIX         install architecture-independent files in PREFIX
#                          [/usr/local]
#  --exec-prefix=EPREFIX   install architecture-dependent files in EPREFIX
#                          [PREFIX]
#
#By default, `make install' will install all the files in
#`/usr/local/bin', `/usr/local/lib' etc.  You can specify
#an installation prefix other than `/usr/local' using `--prefix',
#for instance `--prefix=$HOME'.
#
#For better control, use the options below.
#
#Fine tuning of the installation directories:
#  --bindir=DIR            user executables [EPREFIX/bin]
#  --sbindir=DIR           system admin executables [EPREFIX/sbin]
#  --libexecdir=DIR        program executables [EPREFIX/libexec]
#  --sysconfdir=DIR        read-only single-machine data [PREFIX/etc]
#  --sharedstatedir=DIR    modifiable architecture-independent data [PREFIX/com]
#  --localstatedir=DIR     modifiable single-machine data [PREFIX/var]
#  --libdir=DIR            object code libraries [EPREFIX/lib]
#  --includedir=DIR        C header files [PREFIX/include]
#  --oldincludedir=DIR     C header files for non-gcc [/usr/include]
#  --datarootdir=DIR       read-only arch.-independent data root [PREFIX/share]
#  --datadir=DIR           read-only architecture-independent data [DATAROOTDIR]
#  --infodir=DIR           info documentation [DATAROOTDIR/info]
#  --localedir=DIR         locale-dependent data [DATAROOTDIR/locale]
#  --mandir=DIR            man documentation [DATAROOTDIR/man]
#  --docdir=DIR            documentation root [DATAROOTDIR/doc/xorg-server]
#  --htmldir=DIR           html documentation [DOCDIR]
#  --dvidir=DIR            dvi documentation [DOCDIR]
#  --pdfdir=DIR            pdf documentation [DOCDIR]
#  --psdir=DIR             ps documentation [DOCDIR]
#
#Program names:
#  --program-prefix=PREFIX            prepend PREFIX to installed program names
#  --program-suffix=SUFFIX            append SUFFIX to installed program names
#  --program-transform-name=PROGRAM   run sed PROGRAM on installed program names
#
#System types:
#  --build=BUILD     configure for building on BUILD [guessed]
#  --host=HOST       cross-compile to build programs to run on HOST [BUILD]
#
#Optional Features:
#  --disable-option-checking  ignore unrecognized --enable/--with options
#  --disable-FEATURE       do not include FEATURE (same as --enable-FEATURE=no)
#  --enable-FEATURE[=ARG]  include FEATURE [ARG=yes]
#  --enable-maintainer-mode  enable make rules and dependencies not useful
#			  (and sometimes confusing) to the casual installer
#  --disable-dependency-tracking  speeds up one-time build
#  --enable-dependency-tracking   do not reject slow dependency extractors
#  --enable-strict-compilation
#                          Enable all warnings from compiler and make them
#                          errors (default: disabled)
#  --enable-silent-rules          less verbose build output (undo: `make V=1')
#  --disable-silent-rules         verbose build output (undo: `make V=0')
#  --enable-static[=PKGS]  build static libraries [default=no]
#  --enable-shared[=PKGS]  build shared libraries [default=yes]
#  --enable-fast-install[=PKGS]
#                          optimize for fast installation [default=yes]
#  --disable-libtool-lock  avoid locking (might break parallel builds)
#  --disable-largefile     omit support for large files
#  --enable-werror         Obsolete - use --enable-strict-compilation instead
#  --enable-debug          Enable debugging (default: disabled)
#  --enable-unit-tests     Enable unit-tests (default: auto)
#  --enable-use-sigio-by-default
#  Enable SIGIO input handlers by default (default: $USE_SIGIO_BY_DEFAULT)
#
#  --enable-sparkle        Enable updating of X11.app using the Sparkle
#                          Framework (default: disabled)
#  --enable-builddocs      Build docs (default: disabled)
#  --enable-install-libxf86config
#                          Install libxf86config (default: disabled)
#  --enable-visibility     Enable symbol visibility (default: auto)
#  --enable-pc98           Enable PC98 support in Xorg (default: auto)
#  --enable-aiglx          Build accelerated indirect GLX (default: enabled)
#  --enable-glx-tls        Build GLX with TLS support (default: disabled)
#  --disable-registry      Build string registry module (default: enabled)
#  --disable-composite     Build Composite extension (default: enabled)
#  --disable-shm           Build SHM extension (default: enabled)
#  --disable-xres          Build XRes extension (default: enabled)
#  --disable-record        Build Record extension (default: enabled)
#  --disable-xv            Build Xv extension (default: enabled)
#  --disable-xvmc          Build XvMC extension (default: enabled)
#  --disable-dga           Build DGA extension (default: auto)
#  --disable-screensaver   Build ScreenSaver extension (default: enabled)
#  --disable-xdmcp         Build XDMCP extension (default: auto)
#  --disable-xdm-auth-1    Build XDM-Auth-1 extension (default: auto)
#  --disable-glx           Build GLX extension (default: enabled)
#  --enable-dri            Build DRI extension (default: auto)
#  --enable-dri2           Build DRI2 extension (default: auto)
#  --disable-xinerama      Build Xinerama extension (default: enabled)
#  --disable-xf86vidmode   Build XF86VidMode extension (default: auto)
#  --disable-xace          Build X-ACE extension (default: enabled)
#  --enable-xselinux       Build SELinux extension (default: disabled)
#  --enable-xcsecurity     Build Security extension (default: disabled)
#  --enable-xcalibrate     Build XCalibrate extension (default: disabled)
#  --enable-tslib          Build kdrive tslib touchscreen support (default:
#                          disabled)
#  --disable-dbe           Build DBE extension (default: enabled)
#  --enable-xf86bigfont    Build XF86 Big Font extension (default: disabled)
#  --disable-dpms          Build DPMS extension (default: enabled)
#  --enable-config-udev    Build udev support (default: auto)
#  --enable-config-dbus    Build D-BUS API support (default: no)
#  --disable-config-hal    Build HAL support (default: auto)
#  --enable-xfree86-utils  Build xfree86 DDX utilities (default: enabled)
#  --enable-xaa            Build XAA (default: enabled)
#  --enable-vgahw          Build Xorg with vga access (default: enabled)
#  --enable-vbe            Build Xorg with VBE module (default: enabled)
#  --enable-int10-module   Build Xorg with int10 module (default: enabled)
#  --enable-windowswm      Build XWin with WindowsWM extension (default: no)
#  --enable-libdrm         Build Xorg with libdrm support (default: enabled)
#  --enable-xorg           Build Xorg server (default: auto)
#  --enable-dmx            Build DMX server (default: auto)
#  --enable-xvfb           Build Xvfb server (default: yes)
#  --enable-xnest          Build Xnest server (default: auto)
#  --enable-xquartz        Build Xquartz server for OS-X (default: auto)
#  --enable-standalone-xpbproxy
#                          Build a standalone xpbproxy (in addition to the one
#                          integrated into Xquartz as a separate thread)
#                          (default: no)
#  --enable-xwin           Build XWin server (default: auto)
#  --enable-kdrive         Build kdrive servers (default: no)
#  --enable-xephyr         Build the kdrive Xephyr server (default: auto)
#  --enable-xfake          Build the kdrive 'fake' server (default: auto)
#  --enable-xfbdev         Build the kdrive framebuffer device server (default:
#                          auto)
#  --enable-kdrive-kbd     Build kbd driver for kdrive (default: auto)
#  --enable-kdrive-mouse   Build mouse driver for kdrive (default: auto)
#  --enable-kdrive-evdev   Build evdev driver for kdrive (default: auto)
#  --enable-install-setuid Install Xorg server as owned by root with setuid bit
#                          (default: auto)
#  --enable-unix-transport Enable UNIX domain socket transport
#  --enable-tcp-transport  Enable TCP socket transport
#  --enable-ipv6           Enable IPv6 support
#  --enable-local-transport
#                          Enable os-specific local transport
#  --enable-secure-rpc     Enable Secure RPC
#  --enable-devel-docs     Enable building the developer documentation
#                          (default: yes)
#
#Optional Packages:
#  --with-PACKAGE[=ARG]    use PACKAGE [ARG=yes]
#  --without-PACKAGE       do not use PACKAGE (same as --with-PACKAGE=no)
#  --with-doxygen          Use doxygen to regenerate documentation (default:
#                          auto)
#  --with-pic              try to use only PIC/non-PIC objects [default=use
#                          both]
#  --with-gnu-ld           assume the C compiler uses GNU ld [default=no]
#  --with-sysroot=DIR Search for dependent libraries within DIR
#                        (or the compiler's sysroot if not specified).
#  --with-dtrace=PATH      Enable dtrace probes (default: enabled if dtrace
#                          found)
#  --with-int10=BACKEND    int10 backend: vm86, x86emu or stub
#  --with-vendor-name=VENDOR
#                          Vendor string reported by the server
#  --with-vendor-name-short=VENDOR
#                          Short version of vendor string reported by the
#                          server
#  --with-vendor-web=URL   Vendor web address reported by the server
#  --with-module-dir=DIR   Directory where modules are installed (default:
#                          $libdir/xorg/modules)
#  --with-log-dir=DIR      Directory where log files are kept (default:
#                          $localstatedir/log)
#  --with-builder-addr=ADDRESS
#                          Builder address (default:
#                          xorg@lists.freedesktop.org)
#  --with-os-name=OSNAME   Name of OS (default: output of "uname -srm")
#  --with-os-vendor=OSVENDOR
#                          Name of OS vendor
#  --with-builderstring=BUILDERSTRING
#                          Additional builder string
#  --with-fontrootdir=DIR  Path to root directory for font files
#  --with-fontmiscdir=DIR  Path to misc files [FONTROOTDIR/misc]
#  --with-fontotfdir=DIR   Path to OTF files [FONTROOTDIR/OTF]
#  --with-fontttfdir=DIR   Path to TTF files [FONTROOTDIR/TTF]
#  --with-fonttype1dir=DIR Path to Type1 files [FONTROOTDIR/Type1]
#  --with-font75dpidir=DIR Path to 75dpi files [FONTROOTDIR/75dpi]
#  --with-font100dpidir=DIR
#                          Path to 100dpi files [FONTROOTDIR/100dpi]
#  --with-default-font-path=PATH
#                          Comma separated list of font dirs
#  --with-xkb-path=PATH    Path to XKB base dir (default: ${datadir}/X11/xkb)
#  --with-xkb-output=PATH  Path to XKB output dir (default:
#                          ${datadir}/X11/xkb/compiled)
#  --with-default-xkb-rules=RULES
#                          Keyboard ruleset (default: base/evdev)
#  --with-default-xkb-model=MODEL
#                          Keyboard model (default: pc105)
#  --with-default-xkb-layout=LAYOUT
#                          Keyboard layout (default: us)
#  --with-default-xkb-variant=VARIANT
#                          Keyboard variant (default: (none))
#  --with-default-xkb-options=OPTIONS
#                          Keyboard layout options (default: (none))
#  --with-serverconfig-path=PATH
#                          Directory where ancillary server config files are
#                          installed (default: ${libdir}/xorg)
#  --with-apple-applications-dir=PATH
#                          Path to the Applications directory (default:
#                          /Applications/Utilities)
#  --with-apple-application-name=NAME
#                          Name for the .app (default: X11)
#  --with-launchd-id-prefix=PATH
#                          Prefix to use for launchd identifiers (default:
#                          org.x)
#  --with-dri-driver-path=PATH
#                          Path to DRI drivers (default: ${libdir}/dri)
#  --with-xmlto            Use xmlto to regenerate documentation (default:
#                          auto)
#  --with-fop              Use fop to regenerate documentation (default: auto)
#  --with-xkb-bin-directory=DIR
#                          Directory containing xkbcomp program
#  --with-sha1=libc|libmd|libgcrypt|libcrypto|libsha1|CommonCrypto
#                          choose SHA1 implementation
#
#Some influential environment variables:
#  CC          C compiler command
#  CFLAGS      C compiler flags
#  LDFLAGS     linker flags, e.g. -L<lib dir> if you have libraries in a
#              nonstandard directory <lib dir>
#  LIBS        libraries to pass to the linker, e.g. -l<library>
#  CPPFLAGS    (Objective) C/C++ preprocessor flags, e.g. -I<include dir> if
#              you have headers in a nonstandard directory <include dir>
#  CPP         C preprocessor
#  PKG_CONFIG  path to pkg-config utility
#  PKG_CONFIG_PATH
#              directories to add to pkg-config's search path
#  PKG_CONFIG_LIBDIR
#              path overriding pkg-config's built-in search path
#  DOXYGEN     Path to doxygen command
#  CCAS        assembler compiler command (defaults to CC)
#  CCASFLAGS   assembler compiler flags (defaults to CFLAGS)
#  YACC        The `Yet Another Compiler Compiler' implementation to use.
#              Defaults to the first program found out of: `bison -y', `byacc',
#              `yacc'.
#  YFLAGS      The list of arguments that will be passed by default to $YACC.
#              This script will default YFLAGS to the empty string to avoid a
#              default value of `-d' given by some make applications.
#  XMLTO       Path to xmlto command
#  FOP         Path to fop command
#  PIXMAN_CFLAGS
#              C compiler flags for PIXMAN, overriding pkg-config
#  PIXMAN_LIBS linker flags for PIXMAN, overriding pkg-config
#  UDEV_CFLAGS C compiler flags for UDEV, overriding pkg-config
#  UDEV_LIBS   linker flags for UDEV, overriding pkg-config
#  DBUS_CFLAGS C compiler flags for DBUS, overriding pkg-config
#  DBUS_LIBS   linker flags for DBUS, overriding pkg-config
#  HAL_CFLAGS  C compiler flags for HAL, overriding pkg-config
#  HAL_LIBS    linker flags for HAL, overriding pkg-config
#  XLIB_CFLAGS C compiler flags for XLIB, overriding pkg-config
#  XLIB_LIBS   linker flags for XLIB, overriding pkg-config
#  GL_CFLAGS   C compiler flags for GL, overriding pkg-config
#  GL_LIBS     linker flags for GL, overriding pkg-config
#  DRIPROTO_CFLAGS
#              C compiler flags for DRIPROTO, overriding pkg-config
#  DRIPROTO_LIBS
#              linker flags for DRIPROTO, overriding pkg-config
#  DRI_CFLAGS  C compiler flags for DRI, overriding pkg-config
#  DRI_LIBS    linker flags for DRI, overriding pkg-config
#  DRI2PROTO_CFLAGS
#              C compiler flags for DRI2PROTO, overriding pkg-config
#  DRI2PROTO_LIBS
#              linker flags for DRI2PROTO, overriding pkg-config
#  LIBDRM_CFLAGS
#              C compiler flags for LIBDRM, overriding pkg-config
#  LIBDRM_LIBS linker flags for LIBDRM, overriding pkg-config
#  SELINUX_CFLAGS
#              C compiler flags for SELINUX, overriding pkg-config
#  SELINUX_LIBS
#              linker flags for SELINUX, overriding pkg-config
#  XDMCP_CFLAGS
#              C compiler flags for XDMCP, overriding pkg-config
#  XDMCP_LIBS  linker flags for XDMCP, overriding pkg-config
#  GLIB_CFLAGS C compiler flags for GLIB, overriding pkg-config
#  GLIB_LIBS   linker flags for GLIB, overriding pkg-config
#  LIBSHA1_CFLAGS
#              C compiler flags for LIBSHA1, overriding pkg-config
#  LIBSHA1_LIBS
#              linker flags for LIBSHA1, overriding pkg-config
#  OPENSSL_CFLAGS
#              C compiler flags for OPENSSL, overriding pkg-config
#  OPENSSL_LIBS
#              linker flags for OPENSSL, overriding pkg-config
#  XSERVERCFLAGS_CFLAGS
#              C compiler flags for XSERVERCFLAGS, overriding pkg-config
#  XSERVERCFLAGS_LIBS
#              linker flags for XSERVERCFLAGS, overriding pkg-config
#  XSERVERLIBS_CFLAGS
#              C compiler flags for XSERVERLIBS, overriding pkg-config
#  XSERVERLIBS_LIBS
#              linker flags for XSERVERLIBS, overriding pkg-config
#  XNESTMODULES_CFLAGS
#              C compiler flags for XNESTMODULES, overriding pkg-config
#  XNESTMODULES_LIBS
#              linker flags for XNESTMODULES, overriding pkg-config
#  PCIACCESS_CFLAGS
#              C compiler flags for PCIACCESS, overriding pkg-config
#  PCIACCESS_LIBS
#              linker flags for PCIACCESS, overriding pkg-config
#  DGA_CFLAGS  C compiler flags for DGA, overriding pkg-config
#  DGA_LIBS    linker flags for DGA, overriding pkg-config
#  XF86VIDMODE_CFLAGS
#              C compiler flags for XF86VIDMODE, overriding pkg-config
#  XF86VIDMODE_LIBS
#              linker flags for XF86VIDMODE, overriding pkg-config
#  XORG_MODULES_CFLAGS
#              C compiler flags for XORG_MODULES, overriding pkg-config
#  XORG_MODULES_LIBS
#              linker flags for XORG_MODULES, overriding pkg-config
#  XWINMODULES_CFLAGS
#              C compiler flags for XWINMODULES, overriding pkg-config
#  XWINMODULES_LIBS
#              linker flags for XWINMODULES, overriding pkg-config
#  WINDOWSWM_CFLAGS
#              C compiler flags for WINDOWSWM, overriding pkg-config
#  WINDOWSWM_LIBS
#              linker flags for WINDOWSWM, overriding pkg-config
#  XPBPROXY_CFLAGS
#              C compiler flags for XPBPROXY, overriding pkg-config
#  XPBPROXY_LIBS
#              linker flags for XPBPROXY, overriding pkg-config
#  DMXMODULES_CFLAGS
#              C compiler flags for DMXMODULES, overriding pkg-config
#  DMXMODULES_LIBS
#              linker flags for DMXMODULES, overriding pkg-config
#  XDMXCONFIG_DEP_CFLAGS
#              C compiler flags for XDMXCONFIG_DEP, overriding pkg-config
#  XDMXCONFIG_DEP_LIBS
#              linker flags for XDMXCONFIG_DEP, overriding pkg-config
#  DMXEXAMPLES_DEP_CFLAGS
#              C compiler flags for DMXEXAMPLES_DEP, overriding pkg-config
#  DMXEXAMPLES_DEP_LIBS
#              linker flags for DMXEXAMPLES_DEP, overriding pkg-config
#  DMXXMUEXAMPLES_DEP_CFLAGS
#              C compiler flags for DMXXMUEXAMPLES_DEP, overriding pkg-config
#  DMXXMUEXAMPLES_DEP_LIBS
#              linker flags for DMXXMUEXAMPLES_DEP, overriding pkg-config
#  DMXXIEXAMPLES_DEP_CFLAGS
#              C compiler flags for DMXXIEXAMPLES_DEP, overriding pkg-config
#  DMXXIEXAMPLES_DEP_LIBS
#              linker flags for DMXXIEXAMPLES_DEP, overriding pkg-config
#  XTSTEXAMPLES_DEP_CFLAGS
#              C compiler flags for XTSTEXAMPLES_DEP, overriding pkg-config
#  XTSTEXAMPLES_DEP_LIBS
#              linker flags for XTSTEXAMPLES_DEP, overriding pkg-config
#  XRESEXAMPLES_DEP_CFLAGS
#              C compiler flags for XRESEXAMPLES_DEP, overriding pkg-config
#  XRESEXAMPLES_DEP_LIBS
#              linker flags for XRESEXAMPLES_DEP, overriding pkg-config
#  X11EXAMPLES_DEP_CFLAGS
#              C compiler flags for X11EXAMPLES_DEP, overriding pkg-config
#  X11EXAMPLES_DEP_LIBS
#              linker flags for X11EXAMPLES_DEP, overriding pkg-config
#  TSLIB_CFLAGS
#              C compiler flags for TSLIB, overriding pkg-config
#  TSLIB_LIBS  linker flags for TSLIB, overriding pkg-config
#  XEPHYR_CFLAGS
#              C compiler flags for XEPHYR, overriding pkg-config
#  XEPHYR_LIBS linker flags for XEPHYR, overriding pkg-config
#
#Use these variables to override the choices made by `configure' or to help
#it to find libraries and programs with nonstandard names/locations.
#
#Report bugs to <https://bugs.freedesktop.org/enter_bug.cgi?product=xorg>.
#