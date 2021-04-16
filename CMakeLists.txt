cmake_minimum_required(VERSION 3.10)
project(PropManipulator VERSION 0.5)

set(CMAKE_CXX_FLAGS "-std=c++11")

include(CTest)
enable_testing()

# Add source files
file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/src/*.cpp)
    
# Add header files
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/src/*.hpp)

link_directories(${CMAKE_SOURCE_DIR}/lib)

configure_file(src/helpers/settings.h.in settings.h)

include_directories(${CMAKE_BINARY_DIR}/src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

if (NOT WIN32)
  set(CMAKE_MODULE_PATH /usr/local/lib/cmake /usr/local/lib/x86_64-linux-gnu/cmake)
  set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/glfw)
endif (NOT WIN32)

find_package (OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message("ERROR: OpenGL not found")
endif(NOT OPENGL_FOUND)

# OS specific links
#!!! "C:/GLFW/lib-mingw-w64" must be changed to "C:/GLFW/lib-mingw" if not using 64-bit version !!!
if (WIN32)
  include_directories("C:/GLFW/include" "C:/glm" "C:/glew/include")
  link_directories("C:/glew/lib/Release/x64" "C:/GLFW/lib-mingw-w64" )
else (WIN32)
  find_package (glfw3 REQUIRED)
  find_package (glm REQUIRED)
  find_package (GLEW REQUIRED STATIC)
endif (WIN32)

if (APPLE)
  include_directories(/usr/local/include)
  find_library(COCOA_LIBRARY Cocoa REQUIRED)
  find_library(IOKIT_LIBRARY IOKit REQUIRED)
  find_library(COREVID_LIBRARY CoreVideo REQUIRED)
endif (APPLE)

if (UNIX)
  target_link_libraries (PropManipulator
          ${OPENGL_LIBRARIES}
          ${GLFW3_LIBRARY}
          ${GLEW_LIBRARY}
          GLEW glfw Xxf86vm pthread Xrandr Xinerama Xi Xcursor)
  if(POLICY CMP0072)
          cmake_policy(SET CMP0072 NEW)
  endif()
endif (UNIX)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
  target_link_libraries (PropManipulator
          ${GLFW3_LIBRARY}
          ${OPENGL_LIBRARIES}
          ${GLEW_LIBRARY}
          ${COCOA_LIBRARY} ${COREVID_LIBRARY} ${IOKIT_LIBRARY})
if (WIN32)
  target_link_libraries (${PROJECT_NAME}
          ${OPENGL_LIBRARIES} glew32s glfw3 glu32 opengl32)
endif (WIN32)


# Define the include DIRs
include_directories("${CMAKE_SOURCE_DIR}/src"
	                "${CMAKE_SOURCE_DIR}/include"
                    )

include(CPack)

target_include_directories(PropManipulator PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
