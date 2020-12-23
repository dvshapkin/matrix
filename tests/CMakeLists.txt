add_executable(matrix_test matrix_test.cpp catch.h)

include_directories(../lib)

add_test(
        NAME Test1
        COMMAND matrix_test
)
