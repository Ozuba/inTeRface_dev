cmake_minimum_required(VERSION 3.10)

project(inTeRface)

# Find SDL2
find_package(SDL2 REQUIRED)

# Add LVGL directory (adjust the path as necessary)
add_subdirectory(lvgl) # Change this to your LVGL path
target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR})

# Create the UI lib

file(GLOB UI_SOURCE ui/*.c)
add_library(ter_ui ${UI_SOURCE})
target_include_directories(ter_ui PUBLIC ${PROJECT_SOURCE_DIR})

# Create executable
add_executable(${CMAKE_PROJECT_NAME} 
src/can.c
src/main.c
)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
${CMAKE_SOURCE_DIR}
)

# Link libraries
target_link_libraries(${CMAKE_PROJECT_NAME} ter_ui lvgl SDL2::SDL2)

