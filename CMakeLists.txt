cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(EXECUTABLE_NAME wine)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${EXECUTABLE_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/src/Wine.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/WinePr.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/wine_example.cpp
)
