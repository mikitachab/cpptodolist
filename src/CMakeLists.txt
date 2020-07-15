cmake_minimum_required(VERSION 3.13)

project(${this})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/App.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/Controller/Controller.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/TodosLoader/TodosLoader.cpp
)

add_executable(${this} ${SOURCE})
