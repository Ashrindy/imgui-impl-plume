cmake_minimum_required(VERSION 3.8)
project(imgui_impl_plume LANGUAGES CXX)

add_library(imgui_impl_plume STATIC
    imgui_impl_plume.cpp
)

target_include_directories(imgui_impl_plume PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(imgui_impl_plume PUBLIC imgui plume)
