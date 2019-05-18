# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. PART_1_SRC)

# 生成链接库
add_library(Foundation ${PART_1_SRC})

add_executable(chapter_1_start chapter_1_start.cpp)
add_executable(chapter_2_basic chapter_2_basic.cpp)
add_executable(chapter_3_sva chapter_3_sva.cpp)
add_executable(chapter_4_expression chapter_4_expression.cpp)
add_executable(chapter_5_statement chapter_5_statement.cpp)
add_executable(chapter_6_function chapter_6_function.cpp)

add_executable(chapter_7_class chapter_7_class.cpp)
target_link_libraries(chapter_7_class Foundation)
