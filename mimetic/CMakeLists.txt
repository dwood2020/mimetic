# Level: ./mimetic
# Exposes alias library target `mimetic::mimetic`

set(MIMETIC_LIB_TARGET ${CMAKE_PROJECT_NAME})
add_library(${MIMETIC_LIB_TARGET} STATIC)

set(MIMETIC_SRC ${CMAKE_CURRENT_LIST_DIR})
target_sources(${MIMETIC_LIB_TARGET} PRIVATE
    "${MIMETIC_SRC}/body.cxx"
    "${MIMETIC_SRC}/contentdescription.cxx"
    "${MIMETIC_SRC}/contentdisposition.cxx"
    "${MIMETIC_SRC}/contentid.cxx"
    "${MIMETIC_SRC}/contenttransferencoding.cxx"
    "${MIMETIC_SRC}/contenttype.cxx"
    "${MIMETIC_SRC}/fieldparam.cxx"
    "${MIMETIC_SRC}/header.cxx"
    "${MIMETIC_SRC}/message.cxx"
    "${MIMETIC_SRC}/mimeentity.cxx"
    "${MIMETIC_SRC}/mimeversion.cxx"
    "${MIMETIC_SRC}/strutils.cxx"
    "${MIMETIC_SRC}/utils.cxx"
    "${MIMETIC_SRC}/version.cxx"

    # os
    "${MIMETIC_SRC}/os/file_iterator.cxx"
    "${MIMETIC_SRC}/os/fileop.cxx"
    "${MIMETIC_SRC}/os/mmfile.cxx"
    "${MIMETIC_SRC}/os/stdfile.cxx"
    "${MIMETIC_SRC}/os/utils.cxx"

    # codec
    "${MIMETIC_SRC}/codec/base64.cxx"
    "${MIMETIC_SRC}/codec/qp.cxx"

    # rfc822
    "${MIMETIC_SRC}/rfc822/address.cxx"
    "${MIMETIC_SRC}/rfc822/addresslist.cxx"
    "${MIMETIC_SRC}/rfc822/datetime.cxx"
    "${MIMETIC_SRC}/rfc822/field.cxx"
    "${MIMETIC_SRC}/rfc822/fieldvalue.cxx"
    "${MIMETIC_SRC}/rfc822/group.cxx"
    "${MIMETIC_SRC}/rfc822/header.cxx"
    "${MIMETIC_SRC}/rfc822/mailbox.cxx"
    "${MIMETIC_SRC}/rfc822/mailboxlist.cxx"
    "${MIMETIC_SRC}/rfc822/message.cxx"
    "${MIMETIC_SRC}/rfc822/messageid.cxx"

    # custom
    "${MIMETIC_SRC}/platform_support/mmap.cpp"
)


set(MIMETIC_VERSION "0.9.8")
# TODO: This would need to go into the BINARY_DIR
# configure_file(${CMAKE_SOURCE_DIR}/ext/cmake/mimetic/config.h.in ${MIMETIC_ROOT}/mimetic/config.h)
if (UNIX OR APPLE)
    target_compile_definitions(${MIMETIC_LIB_TARGET} PUBLIC "VERSION=\"${MIMETIC_VERSION}\"")
    target_compile_definitions(${MIMETIC_LIB_TARGET} PUBLIC HAVE_UNISTD_H=1)
    target_compile_definitions(${MIMETIC_LIB_TARGET} PUBLIC HAVE_SYS_TYPES_H=1)
    target_compile_definitions(${MIMETIC_LIB_TARGET} PUBLIC HAVE_SYS_STAT_H=1)
elseif (WIN32)
endif()


target_include_directories(${MIMETIC_LIB_TARGET} PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/.."
)

add_library(mimetic::mimetic ALIAS ${MIMETIC_LIB_TARGET})
