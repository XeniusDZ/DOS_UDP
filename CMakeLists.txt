cmake_minimum_required(VERSION 3.10)

project(DOSAttacker)

include(FetchContent)

add_subdirectory(doctest)

enable_testing()

FetchContent_Declare(
        nana
        GIT_REPOSITORY https://github.com/cnjinhao/nana.git
        GIT_TAG        master
)

FetchContent_GetProperties(nana)
if(NOT nana_POPULATED)
    FetchContent_Populate(nana)
    add_subdirectory(${nana_SOURCE_DIR} ${nana_BINARY_DIR})
endif()

add_executable(main-test udp.h test.cpp)
target_link_libraries(main-test doctest wsock32 ws2_32)
add_test(NAME main-test COMMAND main-test --force-colors -d)

add_executable(main main.cpp GUI.h doctest udp.h)
target_link_libraries(main nana wsock32 ws2_32)

