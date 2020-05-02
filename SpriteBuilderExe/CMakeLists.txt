# CMakeLists for SpriteBuilder executable 

cmake_minimum_required (VERSION 3.8)

add_executable(SpriteBuilderExe 
  "source/main.cpp"
)

target_link_libraries(SpriteBuilderExe PRIVATE SpriteBuilder)

# Include own header files
target_include_directories(SpriteBuilderExe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)