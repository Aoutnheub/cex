cmake_minimum_required(VERSION 3.16)

project(cex VERSION 1.0)

add_library(cexargs STATIC src/args.cpp)
set(_ARGS_HEADERS "include/args.h")
set_target_properties(cexargs PROPERTIES PUBLIC_HEADER "${_ARGS_HEADERS}")
INSTALL(TARGETS cexargs PUBLIC_HEADER DESTINATION include/${PROJECT_NAME})

add_library(cexcolors STATIC src/args.cpp)
set(_COLORS_HEADERS "include/colors.h")
set_target_properties(cexcolors PROPERTIES PUBLIC_HEADER "${_COLORS_HEADERS}")
INSTALL(TARGETS cexcolors PUBLIC_HEADER DESTINATION include/${PROJECT_NAME})

if(BUILD_TESTS)
    add_executable(args_test "test/args.cpp" "src/args.cpp")
    add_executable(colors_test "test/colors.cpp" "src/colors.cpp")
endif()
