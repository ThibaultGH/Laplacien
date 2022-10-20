cmake_minimum_required(VERSION 3.24.2)

project(Laplacien)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(GMSHmesh)

target_link_directories(${PROJECT_NAME} PRIVATE GMSHmesh)

target_include_directories(${PROJECT_NAME} PUBLIC GMSHmesh)

find_library(myblaslib gslcblas DOC "GNU Scientific Library (GSL) -- blas library package" REQUIRED)

if(${myblaslib} STREQUAL "${myblaslib}-NOTFOUND")
  message(FATAL_ERROR "no BLAS lib, sorry")
endif()


find_library(mylapacklib lapack DOC "LAPACK library" REQUIRED)

if(${mylapacklib} STREQUAL "${mylapacklib}-NOTFOUND")
  message(FATAL_ERROR "no LAPACK lib, sorry")
endif()

target_link_libraries(${PROJECT_NAME}
  blas
  lapack
  mesh
)

# add_library(
#   GMSHmesh GMSHmesh/mesh.cpp
# )

