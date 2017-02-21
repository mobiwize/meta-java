PATCHES_URI="\
    file://remove-shell-variables-from-autoheader.patch;striplevel=0 \
    file://filter-aclocal-copy-too.patch;striplevel=0 \
    file://dont-expect-fqpn-for-make.patch;striplevel=0 \
    file://openjdk8-no-genx11-in-headless.patch;apply=no \
    file://openjdk8-no-unused-deps.patch;apply=no \
    file://openjdk8-find-compiler-fix-env-respect.patch;apply=no \
    file://openjdk8-prevent-debuginfo-in-favour-of-openembedded-package-split.patch;apply=no \
"

# Name of the directory containing the compiled output
BUILD_DIR = "openjdk.build"
BUILD_DIR_ECJ = "openjdk.build-ecj"

# Force arm mode for now
ARM_INSTRUCTION_SET_armv4t = "ARM"

# readdir_r was deprecated in glibc-2.24. Ignore the error for now
# NOTE: When updating the recipe, please check if this is still needed
CFLAGS_append = " -Wno-error=deprecated-declarations"

# Currently the arm port supports only the client JIT (or the Zero interpreter)
# For details see (http://mail.openjdk.java.net/pipermail/aarch32-port-dev/2017-February/000750.html)
PACKAGECONFIG_append_arm = " client"

CORBA_CHANGESET = "093c20d822cc"
SRC_URI[corba.md5sum] = "978bd5ebaf495bb99f5a436d60f39587"
SRC_URI[corba.sha256sum] = "571826a06659b5afbe3ec0ea22178c53a6b029ad1b17a763cbe1537d78a3f19e"

HOTSPOT_CHANGESET = "2d40c68f1daa"
SRC_URI[hotspot.md5sum] = "58013c035b578f8f11c4d00ac6ac4e95"
SRC_URI[hotspot.sha256sum] = "2577cfe778f4eab3e392d3772149176936792238e8cfcc5b82bd743007655ca0"

JAXP_CHANGESET = "1bd8db5ce718"
SRC_URI[jaxp.md5sum] = "d6de6091c26dbe0ae2aa7951a677edeb"
SRC_URI[jaxp.sha256sum] = "dcace543a0a61db258e2b05859e63ebdba79910501a29f84f6605e4c1c9010d5"

JAXWS_CHANGESET = "7ed8fcc10d0c"
SRC_URI[jaxws.md5sum] = "a22232cfabb1c6684a9792c1ac5648f6"
SRC_URI[jaxws.sha256sum] = "ed818fab52b5db9ba785ba064ebaff494837205a3c271ff8569a668dac6708a8"

JDK_CHANGESET = "16729db11724"
SRC_URI[jdk.md5sum] = "852107da4bf27fcb93d27bb8752a93fb"
SRC_URI[jdk.sha256sum] = "c011db48e85757615557e04b205c8ebd48a3e249ae0235e172e4ac5a30d34ce4"

LANGTOOLS_CHANGESET = "e371a84a0763"
SRC_URI[langtools.md5sum] = "d73c0ff9d58ffce38ef4bca64868b4e8"
SRC_URI[langtools.sha256sum] = "0c238dc6c6f50c6b1b08d37102c188f70bb04c4628e9b49e6d753db62429e24c"

NASHORN_CHANGESET = "931298dbe3cf"
SRC_URI[nashorn.md5sum] = "61008a331b72d5afbdf52375acd45956"
SRC_URI[nashorn.sha256sum] = "33f3877f81c80150b62cd53fe815eac8ec7fdee6a116f5cedc6208e35380295d"

OPENJDK_CHANGESET = "cb8f12bf1e86"
SRC_URI[openjdk.md5sum] = "0738a58b7f0dd77a638d1127f17a19c3"
SRC_URI[openjdk.sha256sum] = "0b0af46573ed08cedbde4a5bdefa1e8cda63bdb679b5d46be789ec602911fce4"

OPENJDK_HG_U = "jdk8u"
OPENJDK_HG_URL = "http://hg.openjdk.java.net/aarch32-port/${OPENJDK_HG_U}"

OPENJDK_FILE = "${OPENJDK_CHANGESET}.tar.bz2"
OPENJDK_URI = "${OPENJDK_HG_URL}/archive/${OPENJDK_FILE};name=openjdk"

HOTSPOT_FILE = "${HOTSPOT_CHANGESET}.tar.bz2"
HOTSPOT_URI = "${OPENJDK_HG_URL}/hotspot/archive/${HOTSPOT_FILE};name=hotspot;unpack=false"

CORBA_FILE = "${CORBA_CHANGESET}.tar.bz2"
CORBA_URI = "${OPENJDK_HG_URL}/corba/archive/${CORBA_FILE};name=corba;unpack=false"

JAXP_FILE = "${JAXP_CHANGESET}.tar.bz2"
JAXP_URI = "${OPENJDK_HG_URL}/jaxp/archive/${JAXP_FILE};name=jaxp;unpack=false"

JAXWS_FILE = "${JAXWS_CHANGESET}.tar.bz2"
JAXWS_URI = "${OPENJDK_HG_URL}/jaxws/archive/${JAXWS_FILE};name=jaxws;unpack=false"

JDK_FILE = "${JDK_CHANGESET}.tar.bz2"
JDK_URI = "${OPENJDK_HG_URL}/jdk/archive/${JDK_FILE};name=jdk;unpack=false"

LANGTOOLS_FILE = "${LANGTOOLS_CHANGESET}.tar.bz2"
LANGTOOLS_URI = "${OPENJDK_HG_URL}/langtools/archive/${LANGTOOLS_FILE};name=langtools;unpack=false"

NASHORN_FILE = "${NASHORN_CHANGESET}.tar.bz2"
NASHORN_URI = "${OPENJDK_HG_URL}/nashorn/archive/${NASHORN_FILE};name=nashorn;unpack=false"
