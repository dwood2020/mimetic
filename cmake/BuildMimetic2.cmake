# Custom, minimal-invasive CMake build of mimetic library.
# Exposes alias library target `ext::mimetic`.
#
# Upstream repository: https://github.com/tat/mimetic.git

set(LIB_MIMETIC_TARGET mimetic)
add_library(${LIB_MIMETIC_TARGET} STATIC)

set(MIMETIC_ROOT "${CMAKE_CURRENT_LIST_DIR}/..")
target_sources(${LIB_MIMETIC_TARGET} PUBLIC
    "${MIMETIC_ROOT}/mimetic/body.cxx"
    "${MIMETIC_ROOT}/mimetic/contentdescription.cxx"
    "${MIMETIC_ROOT}/mimetic/contentdisposition.cxx"
    "${MIMETIC_ROOT}/mimetic/contentid.cxx"
    "${MIMETIC_ROOT}/mimetic/contenttransferencoding.cxx"
    "${MIMETIC_ROOT}/mimetic/contenttype.cxx"
    "${MIMETIC_ROOT}/mimetic/fieldparam.cxx"
    "${MIMETIC_ROOT}/mimetic/header.cxx"
    "${MIMETIC_ROOT}/mimetic/message.cxx"
    "${MIMETIC_ROOT}/mimetic/mimeentity.cxx"
    "${MIMETIC_ROOT}/mimetic/mimeversion.cxx"
    "${MIMETIC_ROOT}/mimetic/strutils.cxx"
    "${MIMETIC_ROOT}/mimetic/utils.cxx"
    "${MIMETIC_ROOT}/mimetic/version.cxx"

    # os
    "${MIMETIC_ROOT}/mimetic/os/file_iterator.cxx"
    "${MIMETIC_ROOT}/mimetic/os/fileop.cxx"
    "${MIMETIC_ROOT}/mimetic/os/mmfile.cxx"
    "${MIMETIC_ROOT}/mimetic/os/stdfile.cxx"
    "${MIMETIC_ROOT}/mimetic/os/utils.cxx"

    # codec
    "${MIMETIC_ROOT}/mimetic/codec/base64.cxx"
    "${MIMETIC_ROOT}/mimetic/codec/qp.cxx"

    # rfc822
    "${MIMETIC_ROOT}/mimetic/rfc822/address.cxx"
    "${MIMETIC_ROOT}/mimetic/rfc822/addresslist.cxx"
    "${MIMETIC_ROOT}/mimetic/rfc822/datetime.cxx"
    "${MIMETIC_ROOT}/mimetic/rfc822/field.cxx"
    "${MIMETIC_ROOT}/mimetic/rfc822/fieldvalue.cxx"
    "${MIMETIC_ROOT}/mimetic/rfc822/group.cxx"
    "${MIMETIC_ROOT}/mimetic/rfc822/header.cxx"
    "${MIMETIC_ROOT}/mimetic/rfc822/mailbox.cxx"
    "${MIMETIC_ROOT}/mimetic/rfc822/mailboxlist.cxx"
    "${MIMETIC_ROOT}/mimetic/rfc822/message.cxx"
    "${MIMETIC_ROOT}/mimetic/rfc822/messageid.cxx"

    # custom
    "${MIMETIC_ROOT}/mimetic/platform_support/cross_mmap.c"
)


set(MIMETIC_VERSION "0.9.8")
# TODO: This would need to go into the BINARY_DIR
# configure_file(${CMAKE_SOURCE_DIR}/ext/cmake/mimetic/config.h.in ${MIMETIC_ROOT}/mimetic/config.h)
if (UNIX OR APPLE)
    target_compile_definitions(${LIB_MIMETIC_TARGET} PUBLIC "VERSION=${MIMETIC_VERSION}")
    target_compile_definitions(${LIB_MIMETIC_TARGET} PUBLIC HAVE_UNISTD_H=1)
    target_compile_definitions(${LIB_MIMETIC_TARGET} PUBLIC HAVE_SYS_TYPES_H=1)
    target_compile_definitions(${LIB_MIMETIC_TARGET} PUBLIC HAVE_SYS_STAT_H=1)
elseif (WIN32)
endif()


target_include_directories(${LIB_MIMETIC_TARGET} PUBLIC
    "${MIMETIC_ROOT}"
)

add_library(ext::mimetic ALIAS ${LIB_MIMETIC_TARGET})
