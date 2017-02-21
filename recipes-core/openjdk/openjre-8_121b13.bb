require openjdk-8-release-121b13.inc
require openjdk-8-cross.inc

# the following patches can't be applyed on the 121b13 aarch32 sources
PATCHES_URI_remove = "file://openjdk8-fix-shark-build.patch;apply=no"
PATCHES_URI_remove = "file://openjdk8-fix-shark-stdc++11.patch;apply=no"
PATCHES_URI_remove = "file://openjdk8-fix-zero-mode-crash.patch;apply=no"

do_install() {
    rm -rf ${D}${JRE_HOME}
    mkdir -p ${D}${JRE_HOME}
    cp -rp ${B}/images/j2re-image/* ${D}${JRE_HOME}
    chown -R root:root ${D}${JRE_HOME}
    find ${D}${JRE_HOME} -name "*.debuginfo" -print0 | xargs -0 rm
}

FILES_${PN}_append = "\
    ${JRE_HOME}/bin/[a-z]* \
    ${JRE_HOME}/lib/[a-z]* \
    ${JRE_HOME}/LICENSE \
    ${JRE_HOME}/release \
"

FILES_${PN}-dbg_append = "\
    ${JRE_HOME}/bin/.debug/ \
    ${JRE_HOME}/lib/.debug/ \
    ${JRE_HOME}/lib/${JDK_ARCH}/.debug/ \
    ${JRE_HOME}/lib/${JDK_ARCH}/jli/.debug/ \
    ${JRE_HOME}/lib/${JDK_ARCH}/server/.debug/ \
"

FILES_${PN}-doc_append = "\
    ${JRE_HOME}/man \
    ${JRE_HOME}/ASSEMBLY_EXCEPTION \
    ${JRE_HOME}/THIRD_PARTY_README \
"

RPROVIDES_${PN} = "java2-vm"
PROVIDES_${PN} = "java2-vm"
RPROVIDES_${PN} = "java2-runtime"
PROVIDES_${PN} = "java2-runtime"

inherit update-alternatives

ALTERNATIVE_${PN} = "java"
ALTERNATIVE_LINK_NAME[java] = "${bindir}/java"
ALTERNATIVE_TARGET[java] = "${JRE_HOME}/bin/java"
ALTERNATIVE_PRIORITY[java] = "100"
