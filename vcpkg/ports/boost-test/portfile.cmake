# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/test
    REF boost-1.83.0
    SHA512 012277af2c4a58dea27d71699cfeb5f63385c66c43051beea1cdc642acab671bb29a25292b64d8aaa583e2bfb157a614310b5f869d9959d83cbf439081c8282c
    HEAD_REF master
)

vcpkg_replace_string("${SOURCE_PATH}/build/Jamfile.v2"
    "import ../../predef/check/predef"
    "import ../predef/check/predef"
)
file(COPY "${CURRENT_INSTALLED_DIR}/share/boost-predef/check" DESTINATION "${SOURCE_PATH}/predef")
include(${CURRENT_HOST_INSTALLED_DIR}/share/boost-build/boost-modular-build.cmake)
boost_modular_build(SOURCE_PATH ${SOURCE_PATH})
include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})
if(NOT DEFINED VCPKG_BUILD_TYPE OR VCPKG_BUILD_TYPE STREQUAL "release")
    file(MAKE_DIRECTORY ${CURRENT_PACKAGES_DIR}/lib/manual-link)
    file(GLOB MONITOR_LIBS ${CURRENT_PACKAGES_DIR}/lib/*_exec_monitor*)
    file(COPY ${MONITOR_LIBS} DESTINATION ${CURRENT_PACKAGES_DIR}/lib/manual-link)
    file(REMOVE ${MONITOR_LIBS})
endif()

if(NOT DEFINED VCPKG_BUILD_TYPE OR VCPKG_BUILD_TYPE STREQUAL "debug")
    file(MAKE_DIRECTORY ${CURRENT_PACKAGES_DIR}/debug/lib/manual-link)
    file(GLOB DEBUG_MONITOR_LIBS ${CURRENT_PACKAGES_DIR}/debug/lib/*_exec_monitor*)
    file(COPY ${DEBUG_MONITOR_LIBS} DESTINATION ${CURRENT_PACKAGES_DIR}/debug/lib/manual-link)
    file(REMOVE ${DEBUG_MONITOR_LIBS})
endif()
