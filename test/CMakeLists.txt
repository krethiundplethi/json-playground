# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location
cmake_minimum_required(VERSION 3.22)

project(json-playgroundTests LANGUAGES CXX)

# ---- Dependencies ----

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(json-playground_test source/json-playground_test.cpp)
target_link_libraries(
    json-playground_test PRIVATE
    json-playground_lib
    Catch2::Catch2WithMain
)
target_compile_features(json-playground_test PRIVATE cxx_std_17)

catch_discover_tests(json-playground_test)

# ---- End-of-file commands ----

add_folders(Test)
