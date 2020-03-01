cmake_minimum_required (VERSION 3.10)

project(semseterser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(PROJECT_TESTER_NAME ${PROJECT_NAME}_test)

file(GLOB semseterser_src
    RELATIVE ${PROJECT_SOURCE_DIR}
    "src/main.cpp"
    "src/game/*.cpp"
)

# Executable name to be built
add_executable(${PROJECT_NAME} ${semseterser_src})

# Compiler options per platform
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 -O2)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -O2)
endif()

include(GNUInstallDirs)

# Enable downloading external projects during build
include(ExternalProject)

# Enable running ctest
enable_testing()

# Add googletest. Will be downloaded from git.
ExternalProject_Add(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "master"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/googletest
)

# Required for googletest
find_package(Threads REQUIRED)

link_directories(${CMAKE_BINARY_DIR}/googletest/${CMAKE_INSTALL_LIBDIR})
include_directories(${CMAKE_BINARY_DIR}/googletest/${CMAKE_INSTALL_INCLUDEDIR})

# Use all .cpp files in the test folder
file(GLOB_RECURSE TEST_SOURCES
    RELATIVE ${PROJECT_SOURCE_DIR}
    CONFIGURE_DEPENDS
    src/test/*.cpp)

add_executable(${PROJECT_TESTER_NAME} ${TEST_SOURCES})
add_dependencies(${PROJECT_TESTER_NAME} googletest)
target_link_libraries(
    ${PROJECT_TESTER_NAME}
    gtest
    gtest_main
    Threads::Threads
)

add_test(${PROJECT_TESTER_NAME} ${PROJECT_TESTER_NAME})

# Add make tester that builds tests and runs them
add_custom_target(tester
    COMMAND ${PROJECT_TESTER_NAME} || true # suppress verbose errors
    DEPENDS ${PROJECT_TESTER_NAME})

# Exclude googletest building from target "all"
set_target_properties(googletest PROPERTIES EXCLUDE_FROM_ALL TRUE)

# Add SFML
ExternalProject_Add(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG "2.5.1"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/sfml
)

find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)
set(SFML_STATIC_LIBRARIES TRUE)

target_link_libraries(
    ${PROJECT_NAME}
    sfml-graphics
)
