cmake_minimum_required(VERSION 3.11)

# Project Name
project(PongGame)

# Use C++ 17 (Good balance of features and compatibility)
set(CMAKE_CXX_STANDARD 17)

# --- THE MAGIC PART: Download Raylib automatically ---
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        master
)
FetchContent_MakeAvailable(raylib)

# --- Define your source files ---
# List every .cpp file you have here
set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/Ball.cpp
    src/Paddle.cpp
)

# --- Create the Executable ---
add_executable(${PROJECT_NAME} ${SOURCES})

# --- Link Raylib to your executable ---
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# --- Copy assets (optional but helpful) ---
# This copies your "assets" folder to the build folder so the game can find them
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})