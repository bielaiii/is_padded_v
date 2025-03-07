cmake_minimum_required(VERSION 3.10.0)
project(nopadding VERSION 0.1.0 LANGUAGES C CXX)

add_executable(nested_structure nested_structure_no_array_union.cpp)
target_include_directories(nested_structure PRIVATE include)
add_subdirectory(fmt)
#add_executable(plain_structure plain_struct_with_array.cpp)
#target_include_directories(plain_structure PRIVATE include)

add_executable(SimpleReflection simpleReflection.cpp)
target_include_directories(SimpleReflection PRIVATE include
fmt/include


)

set_target_properties(nested_structure PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

#set_target_properties(plain_structure PROPERTIES
#    CXX_STANDARD 17
#    CXX_STANDARD_REQUIRED ON
#    CXX_EXTENSIONS ON
#)

set_target_properties(SimpleReflection PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)

