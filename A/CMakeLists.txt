cmake_minimum_required (VERSION 3.5.2)
project (barra)
set (CMAKE_BUILD_TYPE Release)

if ("${CMAKE_C_COMPILER_ID}" MATCHES "Cray")
  set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -h msglevel_3")
elseif ("${CMAKE_C_COMPILER_ID}" MATCHES "Intel")
  set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fast -Wall")
elseif ("${CMAKE_C_COMPILER_ID}" MATCHES "GNU")
  set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native -Wall")
endif()
message(STATUS "Enabling optimization flags for ${CMAKE_C_COMPILER_ID} Compiler: ${CMAKE_C_FLAGS}")

add_executable (barra barra.c)
