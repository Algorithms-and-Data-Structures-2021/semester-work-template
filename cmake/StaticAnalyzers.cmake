option(ENABLE_CPPCHECK "Enable static analysis with cppcheck" TRUE)
option(ENABLE_CLANG_TIDY "Enable static analysis with clang-tidy" FALSE)

if (ENABLE_CPPCHECK)
    find_program(CPPCHECK cppcheck)
    if (CPPCHECK)
        set(CMAKE_CXX_CPPCHECK
                ${CPPCHECK}
                --suppress=missingInclude
                --enable=all
                --inline-suppr
                --inconclusive
                # -i ${CMAKE_SOURCE_DIR}
                )
    else ()
        message(SEND_ERROR "cppcheck requested but executable not found")
    endif ()
endif ()

if (ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY clang-tidy)
    if (CLANG_TIDY)
        set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY} -extra-arg=-Wno-unknown-warning-option)
    else ()
        message(SEND_ERROR "clang-tidy requested but executable not found")
    endif ()
endif ()
