cmake_minimum_required(VERSION 3.0)
project(Voxel)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# find_package(OpenGL REQUIRED)
find_package(glew REQUIRED)

find_package(glfw3 REQUIRED)

find_package(glm REQUIRED)
# include_directories(${GLM_INCLUDE_DIRS})
# link_directories(${GLM_LIBRARY_DIRS})
# add_definitions(${GLM_DEFINITIONS})

include_directories(
  ./src/
)

# set(ALL_LIBS
#   ${OPENGL_LIBRARY}
#   glfw
#   GLEW_1130  
# )

# Tutorial 1
add_executable(voxel 
  src/main.cpp
  src/util/shader.cpp
  src/util/Vec4.cpp
  src/util/Mat4.cpp
  src/util/Timer.cpp
  src/glfw/Window.cpp
  src/gl/Program.cpp
  src/gl/Mesh.cpp
  src/gl/Transform.cpp
  src/fs/object.cpp
)

target_include_directories(voxel PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(voxel glfw GLEW::GLEW glm)

if (APPLE)
  target_link_libraries(voxel "-framework OpenGL")
endif()