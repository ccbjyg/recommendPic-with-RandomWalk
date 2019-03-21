# 添加头文件路径和资源路径
#之后生成链接库
include_directories(../include)
aux_source_directory(. DIR_LIB_SRCS)

add_library(src SHARED ${DIR_LIB_SRCS})