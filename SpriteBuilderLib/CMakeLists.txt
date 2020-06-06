# CMakeLists for SpriteBuilder library

cmake_minimum_required (VERSION 3.8)
add_library(SpriteBuilder SHARED
  "include/SpriteBuilder.h"
  "include/SpriteBuilder/Core/AnimationRegion.h"
  "include/SpriteBuilder/Core/EventController.h"
  "include/SpriteBuilder/Core/StartupRegion.h"
  "include/SpriteBuilder/Core/TemplateRegion.h"
  "include/SpriteBuilder/Utils/DllUtils.h"
  
  "source/Core/AnimationRegion.cpp"
  "source/Core/EventController.cpp"
  "source/Core/StartupRegion.cpp"
  "source/Core/TemplateRegion.cpp"
  "source/SpriteBuilder.cpp"
)
set_target_properties(SpriteBuilder PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# GameBackbone has SFML as a public target. This means that it is automatically
# added to the target_link_libraries for SpriteBuilder
# SpriteBuilder still needs to find SFML for GB to link against though.
find_package(SFML 2 COMPONENTS network audio graphics window system)

find_package(GameBackbone 0.4.0 REQUIRED) 
target_link_libraries(SpriteBuilder PUBLIC GameBackbone) 

find_package(TGUI 0.8.2 REQUIRED)
target_link_libraries(SpriteBuilder PUBLIC tgui)

message("current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories(SpriteBuilder PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")