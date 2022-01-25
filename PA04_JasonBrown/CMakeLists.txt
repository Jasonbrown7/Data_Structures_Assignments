#CMAKELISTS Jason Brown Project 4 CS302.


cmake_minimum_required(VERSION 2.8.11)

project(proj4)

include_directories(include)

set (CMAKE_CXX_STANDARD 11)


add_executable(main src/Proj4.cpp)



install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")


