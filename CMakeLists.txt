cmake_minimum_required(VERSION 3.15...3.29)
project(explorerscript LANGUAGES CXX)

file(GLOB plugin_src
    "./explorerscript_parser/*.cpp"
)

set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

include(./ExternalAntlr4Cpp.cmake)
include_directories(${ANTLR4_INCLUDE_DIRS})
pybind11_add_module(explorerscript_parser ${plugin_src})
target_link_libraries(explorerscript_parser PRIVATE antlr4_static)

install(TARGETS explorerscript_parser DESTINATION .)
