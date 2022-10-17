cmake_minimum_required(VERSION 3.24.2)

project(Laplacien)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(mesh FileManagerCPP)

target_link_directories(${PROJECT_NAME}
  PRIVATE mesh
  PRIVATE FileManagerCPP
)

target_include_directories(${PROJECT_NAME}
  PUBLIC mesh
  PUBLIC FileManagerCPP
)

add_library(FileManagerCPP FileManagerCPP/FileManagerCPP.cpp)

find_library(myblaslib gslcblas0 DOC "GNU Scientific Library (GSL) -- blas library package" REQUIRED)

if(NOT ${myblaslib})
  message(FATAL_ERROR "no BLAS lib, sorry")
endif()

find_library(mylapacklib lapack DOC "LAPACK library" REQUIRED)

if(NOT ${mylapacklib})
  message(FATAL_ERROR "no LAPACK lib, sorry")
endif()

target_link_libraries(${PROJECT_NAME}
  mesh
  blas
  lapack
  FileManagerCPP
)

