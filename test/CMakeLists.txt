# Level: ./tests

add_executable(cutee
    ${CMAKE_CURRENT_SOURCE_DIR}/cutee.cxx
)

add_executable(test1)
target_sources(test1 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/runtest.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/t.base64.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/t.codec.cxx
)

target_include_directories(test1 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(test1 PUBLIC mimetic::mimetic)
