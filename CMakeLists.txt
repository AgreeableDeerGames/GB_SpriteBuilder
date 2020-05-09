cmake_minimum_required(VERSION 3.8)
project(SpriteBuilder VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 17)


enable_testing()

# top project folder
set(SpriteBuilder_TOP_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})

# project wide output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib CACHE PATH "Output directory for built archive files")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib CACHE PATH "Output directory for built library files")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin CACHE PATH "Output directory for built binary files")

# add custom modules to path
# Note: For this SpriteBuilder, the Modules folder is empty, but for actual projects, we will likely need to do this.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/Modules)

# set postfix
if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX -d)
endif()

add_subdirectory("SpriteBuilderExe")
add_subdirectory("SpriteBuilderLib")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Resources/TGUI_Widgets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})