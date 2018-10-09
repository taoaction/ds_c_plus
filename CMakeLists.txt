cmake_minimum_required(VERSION 3.12)


set(CMAKE_CXX_STANDARD 14)

project(ds-c-plus)

# set(CMAKE_BUILD_TYPE RelWithDebInfo)

#add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
#add_definitions(-Wunused-result)

#
# test1
#

file(GLOB_RECURSE TEST1_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/array/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/array/*.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/test1/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/test1/*.hpp
        )

list(SORT TEST1_SOURCES)
source_group("Source Files" "${CMAKE_CURRENT_SOURCE_DIR}" ${TEST1_SOURCES})

add_executable(test1 ${TEST1_SOURCES})
#target_link_libraries(steward -luv -lpthread -lglog)

# #
# # test2
# #

# file(GLOB_RECURSE TEST2_SOURCES
#         ${CMAKE_CURRENT_SOURCE_DIR}/src/test2/*.h
#         ${CMAKE_CURRENT_SOURCE_DIR}/src/test2/*.cpp
#         )

# list(SORT TEST2_SOURCES)
# source_group("Source Files" "${CMAKE_CURRENT_SOURCE_DIR}/src" ${TEST2_SOURCES})

# add_executable(test2 ${TEST2_SOURCES})

# #
# # test3
# #

# file(
#         GLOB_RECURSE TEST3_SOURCES
#         ${CMAKE_CURRENT_SOURCE_DIR}/src/test3.cpp
# )

# list(SORT TEST3_SOURCES)
# source_group("Source Files" "${CMAKE_CURRENT_SOURCE_DIR}/src" ${TEST3_SOURCES})

# add_executable(test3 ${TEST3_SOURCES})
