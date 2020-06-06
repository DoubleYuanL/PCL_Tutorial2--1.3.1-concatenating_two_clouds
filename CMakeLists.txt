cmake_minimum_required(VERSION 2.8 FATAL_ERROR) 
project(concatenating_two_clouds) 
find_package(PCL 1.2 REQUIRED) 
include_directories(${PCL_INCLUDE_DIRS}) 
link_directories(${PCL_LIBRARY_DIRS}) 
add_definitions(${PCL_DEFINITIONS}) 
add_executable(concatenating_two_clouds concatenating_two_clouds.cpp) 
target_link_libraries(concatenating_two_clouds ${PCL_LIBRARIES})

