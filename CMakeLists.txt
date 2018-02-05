cmake_minimum_required(VERSION 2.8.3)
project(HRBFQI)

set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/DataStructure
                        ${CMAKE_SOURCE_DIR}/HRBFQI
                        ${CMAKE_SOURCE_DIR}/numericalC
                        ${CMAKE_SOURCE_DIR}/polygonizer
                        ${CMAKE_SOURCE_DIR}/PQP/include
                        ${CMAKE_SOURCE_DIR}/PQP/src )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w") #supress all warnings
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DAPC_CAPTURE_DEBUG=1")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O2") #optimizations


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")


find_package(Eigen3 REQUIRED)
find_package(OpenMP REQUIRED)


if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
    add_definitions(${OpenMP_CXX_FLAGS})
endif()

include_directories(${PROJECT_INCLUDE_DIR} )
include_directories(${EIGEN3_INCLUDE_DIR})


file(GLOB DATA_STRUCTURE_SRC ${CMAKE_SOURCE_DIR}/DataStructure/*.c*)
file(GLOB HRBFQI_SRC ${CMAKE_SOURCE_DIR}/HRBFQI/*.c*)
file(GLOB NUMERICAL_SRC ${CMAKE_SOURCE_DIR}/numericalC/*.c*)
file(GLOB POLYGONIZER_SRC ${CMAKE_SOURCE_DIR}/polygonizer/*.c*)
file(GLOB PQP_SRC ${CMAKE_SOURCE_DIR}/PQP/src/*.c*)

#DARPA PARSER
# file( GLOB DARPA_LIB_SOURCES ${CMAKE_SOURCE_DIR}/deps/darpa/*.c )
# file( GLOB DARPA_LIB_HEADERS ${CMAKE_SOURCE_DIR}/deps/darpa/*.h )
# add_library( DARPA_LIB ${DARPA_LIB_SOURCES} ${DARPA_LIB_HEADERS} )
# set_target_properties(DARPA_LIB PROPERTIES LINKER_LANGUAGE C)

message(${HRBFQI_SRC})

add_executable(HRBFQI   ${HRBFQI_SRC}
                        ${DATA_STRUCTURE_SRC}
                        ${NUMERICAL_SRC}
                        ${POLYGONIZER_SRC}
                        ${PQP_SRC})
