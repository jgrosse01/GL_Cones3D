cmake_minimum_required(VERSION 3.23)
project(GL_Cones)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SRC ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/*.h)

find_package(OpenGL REQUIRED)

add_executable(GL_Cones main.cpp ${SRC})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OPENGL_LIBRARIES} -lfreeglut)
