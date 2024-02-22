cmake_minimum_required(VERSION 3.25)
project(ShootingGame)

set(CMAKE_CXX_STANDARD 17)

set(GLEW_H /Users/chengxinwu/Desktop/软件/glew/2.2.0_1/include/GL)
set(GLFW_H /Users/chengxinwu/Desktop/软件/glfw/3.3.8/include/GLFW)
set(GLAD_H /Users/chengxinwu/Desktop/软件/glad/include/glad)
set(KH_H /Users/chengxinwu/Desktop/软件/glad/include/KHR)
include_directories(${GLEW_H} ${GLFW_H} ${GLAD_H} ${KH_H})
include_directories(glm/include)

set(GLEW_LINK /Users/chengxinwu/Desktop/软件/glew/2.2.0_1/lib/libGLEW.2.2.0.dylib)
set(GLFW_LINK /Users/chengxinwu/Desktop/软件/glfw/3.3.8/lib/libglfw.3.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

set(SOURCE_FILES "src/glad.c" "main.cpp" vertexSource/RectangleData.h Camera.h vertexSource/lightData.h vertexSource/AimData.h)
add_executable(ShootingGame ${SOURCE_FILES})


if (APPLE)
    target_link_libraries(ShootingGame "-framework OpenGL")
    target_link_libraries(ShootingGame "-framework GLUT")
endif()
