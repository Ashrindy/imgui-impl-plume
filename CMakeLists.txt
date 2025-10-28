cmake_minimum_required(VERSION 3.8)
project(imgui-impl-plume LANGUAGES CXX)

add_library(imgui-impl-plume STATIC
    imgui_impl_plume.cpp
)

target_include_directories(imgui-impl-plume PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(imgui-impl-plume PUBLIC imgui plume)
