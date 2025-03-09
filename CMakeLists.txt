cmake_minimum_required(VERSION 3.10.0)
project(nopadding VERSION 0.1.0 LANGUAGES C CXX)

add_executable(nested_structure nested_structure_no_array_union.cpp)
target_include_directories(nested_structure PRIVATE include)
add_subdirectory(fmt)
#add_executable(plain_structure plain_struct_with_array.cpp)
#target_include_directories(plain_structure PRIVATE include)

add_library(simpleRft INTERFACE)
target_include_directories(simpleRft INTERFACE include
    #${CMAKE_SOURCE_DIR}/fmt/include/fmt

)

add_executable(SimpleReflection simpleReflection.cpp)


add_executable(TestSimpleReflection test_simpleReflection.cpp)


target_link_libraries(SimpleReflection PRIVATE simpleRft fmt::fmt)
target_link_libraries(TestSimpleReflection PRIVATE simpleRft)

set_target_properties(nested_structure PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

set_target_properties(simpleRft PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

set_target_properties(SimpleReflection PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

