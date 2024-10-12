cmake_minimum_required(VERSION 3.10)

project(inTeRface)

# Find SDL2
find_package(SDL2 REQUIRED)

# Add LVGL directory (adjust the path as necessary)
add_subdirectory(lvgl) # Change this to your LVGL path
target_include_directories(lvgl PUBLIC ${PROJECT_SOURCE_DIR})


include_directories(
${CMAKE_SOURCE_DIR}
ui
src
)
# Create executable
add_executable(${CMAKE_PROJECT_NAME} 
src/main.c
ui/inTeRface.c
)

# Link libraries
target_link_libraries(${CMAKE_PROJECT_NAME} lvgl SDL2::SDL2)

