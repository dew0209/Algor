cmake_minimum_required(VERSION 3.15)
project(JZ_offer)

set(CMAKE_CXX_STANDARD 14)

# 遍历项目根目录下所有的 .cpp 文件
file (GLOB files run/*.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} acwing/dp/high/1/275.cpp leetcode/0923.cpp leetcode/code/55.cpp leetcode/code/122.cpp leetcode/code/45.cpp acwing/dp/high/2/1017.cpp acwing/dp/high/2/1014.cpp acwing/dp/high/2/482.cpp acwing/dp/high/2/1012.cpp acwing/dp/high/2/1016.cpp acwing/dp/high/2/1010.cpp acwing/dp/high/2/187.cpp acwing/dp/high/2/272.cpp leetcode/0924.cpp acwing/dp/high/3/423.cpp acwing/dp/high/3/1024.cpp acwing/dp/high/3/1022.cpp acwing/dp/high/3/278.cpp acwing/dp/high/3/1023.cpp acwing/dp/high/3/1021.cpp acwing/dp/high/3/532_.cpp acwing/dp/high/3/6_.cpp acwing/dp/high/3/1019.cpp acwing/dp/high/3/7.cpp acwing/dp/high/3/8.cpp acwing/dp/high/3/1020.cpp acwing/dp/high/3/1013.cpp acwing/dp/high/3/426.cpp acwing/dp/high/3/10_.cpp acwing/dp/high/3/11_.cpp acwing/dp/high/3/12.cpp acwing/dp/high/3/487_.cpp acwing/dp/high/3/734_.cpp leetcode/lcp2021team/lcp45.cpp leetcode/lcp2021team/lcp46.cpp acwing/contest/18/a.cpp acwing/contest/18/b.cpp acwing/contest/18/c.cpp leetcode/lcp2021team/lcp44.cpp leetcode/0925.cpp)
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()