cmake_minimum_required(VERSION 3.10)

project(learn_macos_internals LANGUAGES C)

add_executable(uname uname.c)
set_target_properties(uname PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../exec"
)

add_executable(sysctl sysctl.c)
set_target_properties(sysctl PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../exec"
)
