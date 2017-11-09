project(ExtendedKF)
cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++11)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3 -g")

set(main
  src/main.cpp)

set(test
  test/main.cpp)

set(sources
  src/application.cpp
  src/protocol.cpp
  src/model.cpp
  src/laser.cpp
  src/radar.cpp
  src/application.h
  src/protocol.h
  src/model.h
  src/laser.h
  src/radar.h
  src/tools.h
  src/kalman_filter.h
  )

set(tests
  test/test_tools.cpp
  test/test_rubric.cpp
  test/test_measurement.cpp
  test/test_model.cpp
  test/test_radar.cpp
  )

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl")
endif()

find_package(ZLIB REQUIRED)
find_package(OpenSSL REQUIRED)

include_directories(${OPENSSL_INCLUDE_DIR})

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 
  include_directories(/usr/local/include)
  find_library(UWS_LIB uWS)
  if(NOT UWS_LIB)
    message(FATAL_ERROR "uWS library not found")
  endif()

  find_library(UV_LIB uv)
  if(NOT UV_LIB)
    message(FATAL_ERROR "uv library not found")
  endif()
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 

add_executable(ExtendedKF ${sources} ${main})
add_executable(Test ${sources} ${tests} ${test})

enable_testing()
add_test(NAME UT COMMAND Test)

target_link_libraries(ExtendedKF 
  ${ZLIB_LIBRARIES} 
  ${OPENSSL_LIBRARIES} 
  ${UV_LIB}
  ${UWS_LIB})
