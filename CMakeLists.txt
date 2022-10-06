cmake_minimum_required(VERSION 3.24.2)

project(Laplacien)

add_executable(${PROJECT_NAME} main.cpp)

find_library(myblaslib gslcblas0 DOC "GNU Scientific Library (GSL) -- blas library package" REQUIRED)

if(${myblaslib})
  message(FATAL_ERROR "no BLAS lib, sorry")
endif()

target_link_libraries(${PROJECT_NAME} blas)
