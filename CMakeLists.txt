cmake_minimum_required(VERSION 3.15)
project(JZ_offer)

set(CMAKE_CXX_STANDARD 14)

# 遍历项目根目录下所有的 .cpp 文件
file (GLOB files run/*.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} acwing/dp/high/1/275.cpp leetcode/0923.cpp leetcode/code/55.cpp leetcode/code/122.cpp leetcode/code/45.cpp acwing/dp/high/2/1017.cpp acwing/dp/high/2/1014.cpp acwing/dp/high/2/482.cpp acwing/dp/high/2/1012.cpp acwing/dp/high/2/1016.cpp acwing/dp/high/2/1010.cpp acwing/dp/high/2/187.cpp acwing/dp/high/2/272.cpp)
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()