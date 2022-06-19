cmake_minimum_required(VERSION 3.12  FATAL_ERROR)

project(nana-cmake
        VERSION 0.1
        LANGUAGES CXX
        )

include(FetchContent)

if(MSVC)
    FetchContent_Declare(
            nana
            GIT_REPOSITORY https://github.com/cnjinhao/nana.git
            GIT_TAG        develop-1.8
    )
else()
    FetchContent_Declare(
            nana
            GIT_REPOSITORY https://github.com/cnjinhao/nana.git
            GIT_TAG        master
    )
endif()

FetchContent_GetProperties(nana)
if(NOT nana_POPULATED)
    FetchContent_Populate(nana)
    add_subdirectory(${nana_SOURCE_DIR} ${nana_BINARY_DIR})
endif()



add_executable(main
        main.cpp
        GUI.h doctest.h udp.h test.cpp)

target_link_libraries(main
        nana
        )

target_compile_features(main
        PUBLIC
        cxx_std_17
        )

