# cmake .. -G "MinGW Makefiles"
# D:\mingw64\bin\mingw32-make.exe

PROJECT(cxx_template)

CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

ADD_EXECUTABLE(tuple_test
               ${CMAKE_CURRENT_SOURCE_DIR}/tuple_test.cc
               ${CMAKE_CURRENT_SOURCE_DIR}/tuple.h)

ADD_EXECUTABLE(thread_pool_test 
              ${CMAKE_CURRENT_SOURCE_DIR}/thread_pool_test.cc
              ${CMAKE_CURRENT_SOURCE_DIR}/thread_pool.h)
