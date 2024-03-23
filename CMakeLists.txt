cmake_minimum_required(VERSION 3.2)
project(MinecraftGL VERSION 0.0.1)

file(GLOB srcFiles
    "src/*.h"
    "src/*.c"
)

file(GLOB includeFiles
    "include/*.h"
)

add_library(glad lib/glad/glad.h lib/glad/khrplatform.h lib/glad/glad.c)

add_executable(${PROJECT_NAME} ${srcFiles})

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glad)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)