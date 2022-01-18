cmake_minimum_required(VERSION 3.16)

project(cex VERSION 1.0)

add_library(cexargs STATIC src/args.cpp)
set(_ARGS_HEADERS "include/args.h")
set_target_properties(cexargs PROPERTIES PUBLIC_HEADER "${_ARGS_HEADERS}")
INSTALL(TARGETS cexargs PUBLIC_HEADER DESTINATION include/${PROJECT_NAME})
