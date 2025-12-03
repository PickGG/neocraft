cmake_minimum_required(VERSION 3.10)

project(NeoCraft)

# Ищет ВСЕ .cpp файлы в src/ и всех поддиректориях
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
add_executable(neocraft ${SRC_FILES})

target_compile_features(neocraft PRIVATE cxx_std_20)
