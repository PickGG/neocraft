cmake_minimum_required(VERSION 3.10)

project(NeoCraft)

find_package(RmlUi REQUIRED)
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")
add_executable(neocraft ${SRC_FILES})
target_compile_features(neocraft PRIVATE cxx_std_20)
target_link_libraries(neocraft PRIVATE SDL3::SDL3)
target_link_libraries(neocraft PRIVATE SDL3_image::SDL3_image)
target_link_libraries(neocraft PRIVATE RmlUi::RmlUi)