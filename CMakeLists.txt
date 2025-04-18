# =======================
#      Minimal version of CMake
# =======================
cmake_minimum_required(VERSION 3.10)

# =======================
#     Project name
# =======================
project(ZeroHeaven)

# =======================
#        Compiler
# =======================
set(CMAKE_CXX_COMPILER "clang++")

# =======================
#    Debug/Release flags
# =======================
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -std=c++17 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra -std=c++17 -O2")

# =======================
#      Directories
# =======================
include_directories(/usr/local/include/SDL3)

# =======================
#      Sources & Objects
# =======================
set(SRC_DIRS
    src/cpp
)

set(SOURCES
    ${SRC_DIRS}/Camera/Camera.cpp
    ${SRC_DIRS}/Entity/Entity.cpp
    ${SRC_DIRS}/Entity/player/Player.cpp
    ${SRC_DIRS}/Entity/player/playerHandling.cpp
    ${SRC_DIRS}/event.cpp
    ${SRC_DIRS}/init.cpp
    ${SRC_DIRS}/main.cpp
    ${SRC_DIRS}/Settings.cpp
    ${SRC_DIRS}/Structures/Structures.cpp
)

# =======================
#      Executable
# =======================
add_executable(app ${SOURCES})

# =======================
#     Linking SDL3
# =======================
target_link_libraries(app /usr/local/lib/libSDL3.so)

# =======================
#      Clean
# =======================
set(CLEAN_FILES
    build
)

# =======================
#      Install rules
# =======================
install(TARGETS app DESTINATION /usr/local/bin)

