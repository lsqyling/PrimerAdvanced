set(PART_4_SRC
        chapter_17_speciallib.cpp
        chapter_18_largeprogramtools.cpp
        Panda.h
        chapter_19_specializedtools.cpp Token.cpp Token.h)



add_library(Advancedtheme ${PART_4_SRC})

add_executable(chapter_17_speciallib chapter_17_speciallib.cpp)

add_executable(chapter_18_largeprogramtools chapter_18_largeprogramtools.cpp)

add_executable(chapter_19_specializedtools chapter_19_specializedtools.cpp)
target_link_libraries(chapter_19_specializedtools Foundation)