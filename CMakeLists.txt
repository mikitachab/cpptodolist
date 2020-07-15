cmake_minimum_required(VERSION 3.13)
include(FetchContent)

set(this todo)

FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


project(${this})

add_subdirectory(src)

target_link_libraries(${this} PRIVATE boost_program_options
                              PRIVATE nlohmann_json::nlohmann_json
)
