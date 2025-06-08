add_executable(test_datum_utils
    test_datum_utils.c
    ${CMAKE_SOURCE_DIR}/src/datum_utils.c
    ${CMAKE_SOURCE_DIR}/src/thirdparty_base58.c
    ${CMAKE_SOURCE_DIR}/src/thirdparty_segwit_addr.c
)

# Link against libsodium and libm for datum_utils.c dependencies
target_link_libraries(test_datum_utils PRIVATE
    ${SODIUM_LIBRARIES} ${SODIUM_LDFLAGS} ${SODIUM_LDFLAGS_OTHER}
    m
)

# Include headers from src directory
target_include_directories(test_datum_utils PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}
)

add_test(NAME datum_utils_test COMMAND test_datum_utils)
