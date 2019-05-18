cmake_minimum_required(VERSION 3.13)
project(PrimerAdvanced)

set(CMAKE_CXX_STANDARD 14)


# Generally not used, it is easy to trigger a duplicate name.
#include_directories(common)
#include_directories(part_1_foundation)
#include_directories(part_2_stdlib)


#libcxx which we will use with specific version of clang
set(LIBCXX_INC_PATH /usr/include/c++/v1)
set(LIBCXX_LIB_PATH /usr/lib)


set(CMAKE_CXX_FLAGS "\
                -Wall -Wextra -Wstrict-aliasing -Wunreachable-code -Wcast-qual -Wctor-dtor-privacy \
                -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-include-dirs -Wswitch-default \
                -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wstrict-overflow=5 -Wswitch-default -Wundef \
                -Wno-variadic-macros -Wno-comment -Wno-parentheses -Wno-unused-function -Wno-unused-parameter -Wno-unused -Wno-documentation -fdiagnostics-show-option -ferror-limit=10 \
                ${CMAKE_CXX_FLAGS}")

set(CMAKE_CXX_FLAGS "\
                    -isystem ${LIBCXX_INC_PATH} \
                    -D__CLANG__ ${CMAKE_CXX_FLAGS}")
# -v can disply information about compilation environment.
#set(CMAKE_EXE_LINKER_FLAGS "\
#                   ${CMAKE_EXE_LINKER_FLAGS} -v -nodefaultlibs -lc++ -lc++abi -lm -lc -lgcc_s -lgcc -ldl \
#                    -L ${LIBCXX_LIB_PATH}")

set(CMAKE_EXE_LINKER_FLAGS "\
                    ${CMAKE_EXE_LINKER_FLAGS} -nodefaultlibs -v -lc++ -lc++abi -lm -lc -lgcc_s -lgcc -ldl \
                    -L ${LIBCXX_LIB_PATH}")


find_package(Boost REQUIRED)

if(NOT Boost_FOUND)
    message("Not found Boost")
endif()

include_directories(${Boost_INCLUDE_DIRS})
message("${Boost_INCLUDE_DIRS}")
message("${Boost_LIBRARY_DIRS}")




add_subdirectory(part_1_foundation)
add_subdirectory(part_2_stdlib)
add_subdirectory(part_3_classdesignertool)
add_subdirectory(part_4_advancedtheme)
add_subdirectory(part_5_templates)







