cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    json-playground
    VERSION 0.1.0
    DESCRIPTION "Just playing around with json libraries"
    HOMEPAGE_URL "https://fellnhofer.engineering/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    json-playground_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    json-playground_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(json-playground_lib PUBLIC cxx_std_17)

find_package(fmt REQUIRED)
target_link_libraries(json-playground_lib PRIVATE fmt::fmt)

# ---- Declare executable ----

add_executable(json-playground_exe source/main.cpp)
add_executable(json-playground::exe ALIAS json-playground_exe)

set_property(TARGET json-playground_exe PROPERTY OUTPUT_NAME json-playground)

target_compile_features(json-playground_exe PRIVATE cxx_std_17)

target_link_libraries(json-playground_exe PRIVATE json-playground_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT json-playground_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of json-playground"
  )
endif()

include(cmake/dev-mode.cmake)
