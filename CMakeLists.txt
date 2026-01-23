cmake_minimum_required(VERSION 3.10)

project(NeoCraft)

find_package(SDL3 REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

add_executable(neocraft ${SRC_FILES})

target_compile_features(neocraft PRIVATE cxx_std_20)

target_link_libraries(neocraft PRIVATE
    SDL3::SDL3
    OpenGL::GL
)
