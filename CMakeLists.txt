cmake_minimum_required(VERSION 3.15...3.29)
project(explorerscript LANGUAGES CXX)

set(CMAKE_POSITION_INDEPENDENT_CODE "ON")

if(APPLE)
    execute_process(
        COMMAND brew --prefix llvm
        OUTPUT_VARIABLE HOMEBREW_LLVM_PREFIX
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if(HOMEBREW_LLVM_PREFIX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${HOMEBREW_LLVM_PREFIX}/lib/c++ -stdlib=libc++")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L${HOMEBREW_LLVM_PREFIX}/lib/c++ -stdlib=libc++")
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -L${HOMEBREW_LLVM_PREFIX}/lib/c++ -stdlib=libc++")
        include_directories(${HOMEBREW_LLVM_PREFIX}/include)
        list(APPEND CMAKE_PREFIX_PATH ${HOMEBREW_LLVM_PREFIX})
    else()
        message(WARNING "Homebrew LLVM not found. Using system default, this might or might not work.")
    endif()
endif()

if(MSVC)
    set(CMAKE_SUPPORT_WINDOWS_EXPORT_ALL_SYMBOLS 1)
endif()

file(GLOB plugin_src
    "./explorerscript_parser/*.cpp"
)

set(CMAKE_CXX_STANDARD 17)
set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

add_definitions(-DANTLR4CPP_STATIC)
set(ANTLR4_WITH_STATIC_CRT OFF)
include(./ExternalAntlr4Cpp.cmake)
include_directories(${ANTLR4_INCLUDE_DIRS})
pybind11_add_module(explorerscript_parser ${plugin_src})
target_link_libraries(explorerscript_parser PRIVATE antlr4_static)

install(TARGETS explorerscript_parser DESTINATION .)
