cmake_minimum_required(VERSION 2.8)
project(TypeAsValue)

set(
	CMAKE_CXX_FLAGS
	"-std=c++14 -W -Wall -Wextra -Winline -pedantic"
)

include_directories(
	src/
)

add_executable(
	tests
	test.cc
)
