cmake_minimum_required(VERSION 3.10)

# set the project name
project(GLEngine VERSION 1.0)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(OpenGL_GL_PREFERENCE GLVND)

# Add source files
file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/src/*.c
	${CMAKE_SOURCE_DIR}/src/*.cpp)
	
# Add header files
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/src/*.h
	${CMAKE_SOURCE_DIR}/src/*.hpp)

find_package(GLFW3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_directories(${GLFW_LIBRARY_DIRS})
add_definitions(${GLFW_DEFINITIONS})

if(NOT GLFW3_FOUND)
        message(Error "   -> GLFW not found.")
else(GLFW3_FOUND)
        message("   -> GLFW found ${GLFW3_LIBRARY}.")
endif(NOT GLFW3_FOUND)


find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

if(NOT OpenGL_FOUND)
        message(Error "   -> OpenGL not found")
else(OpenGL_FOUND)
        message("   -> OpenGL found ${OPENGL_LIBRARIES}.")
endif(NOT OpenGL_FOUND)

#find_package(GLM REQUIRED)
#include_directories(${GLM_INCLUDE_DIRS})
#link_directories(${GLM_LIBRARY_DIRS})
#add_definitions(${GLM_DEFINITIONS})

#if(NOT GLM_FOUND)
#        message(Error "   -> GLM not found")
#else(GLM_FOUND)
#        message("   -> GLM found.)
#endif(NOT GLM_FOUND)

set(LIBS glfw OpenGL::GL)

# add the executable
add_executable(GLEngine ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME} ${LIBS})