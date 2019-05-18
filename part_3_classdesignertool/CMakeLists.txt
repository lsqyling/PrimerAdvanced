

set(PART_3_SRC
        chapter_13_copycontrol.cpp
        chapter_14_overloadops.cpp
        chapter_15_obj-oriented.cpp
        SalesData.cpp SalesData.h
        Quote.cpp Quote.h
        BulkQuote.cpp BulkQuote.h
        QuanityBulkQuote.cpp QuanityBulkQuote.h
        DiscQuote.cpp DiscQuote.h
        Basket.cpp Basket.h
        TextQuery.cpp TextQuery.h
        Query.cpp Query.h
        QueryBase.cpp QueryBase.h
        chapter_16_template.cpp
        Vector.h String.h)


add_library(Clasdesigntool ${PART_3_SRC})




add_executable(chapter_13_copycontrol chapter_13_copycontrol.cpp)

add_executable(chapter_14_overloadops chapter_14_overloadops.cpp)

add_executable(chapter_15_obj-oriented chapter_15_obj-oriented.cpp)
target_link_libraries(chapter_15_obj-oriented Clasdesigntool)


add_executable(chapter_16_template chapter_16_template.cpp)


