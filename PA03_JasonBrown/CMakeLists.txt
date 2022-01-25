#CMAKELISTS Jason Brown Project 3 CS302.


cmake_minimum_required(VERSION 2.8.11)

project(sort)

include_directories(include)

set (CMAKE_CXX_STANDARD 11)


add_executable(proj src/proj3.cpp)
add_executable(alg src/sortingAlgos.cpp)


install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")


