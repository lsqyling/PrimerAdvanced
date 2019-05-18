#
#aux_source_directory(. PART_2_SRC)

set(PART_2_SRC
        chapter_8_io.cpp
        chapter_9_seqcontainers.cpp
        Stack.h
        StackApply.cpp
        chapter_10_genericalg.cpp
        chapter_11_assocontainers.cpp
        PrintFormat.h
        chapter_12_dynamemory.cpp
        StrBlob.cpp StrBlob.h
        TreeNode.cpp TreeNode.h
        StrBlobPtr.cpp StrBlobPtr.h
        Vector.h TextQuery.cpp TextQuery.h
        text_stream/Text.cpp text_stream/Text.h
        text_stream/UtfText.cpp text_stream/UtfText.h
        text_stream/GbkText.cpp text_stream/GbkText.h
        text_stream/TextFactory.cpp text_stream/TextFactory.h)


add_library(Stdlib ${PART_2_SRC})





add_executable(chapter_8_io chapter_8_io.cpp)

add_executable(chapter_9_seqcontainers chapter_9_seqcontainers.cpp)
target_link_libraries(chapter_9_seqcontainers Stdlib)

add_executable(chapter_10_genericalg chapter_10_genericalg.cpp)
target_link_libraries(chapter_10_genericalg Stdlib Foundation)

add_executable(chapter_11_assocontainers chapter_11_assocontainers.cpp)

add_executable(chapter_12_dynamemory chapter_12_dynamemory.cpp)
target_link_libraries(chapter_12_dynamemory Stdlib)
