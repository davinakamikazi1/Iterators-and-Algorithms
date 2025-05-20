# Set minimum CMAKE
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project( IteratorsAndAlgorithms )

# require C++20
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( APP_EXECUTABLE IteratorTest )

set( LIB_NAME myClassLibrary)

# Add things from inc
add_library( ${LIB_NAME} INTERFACE  )
target_sources(${LIB_NAME}
    INTERFACE
        inc/iterators.hpp
)

target_include_directories( ${LIB_NAME} INTERFACE inc )

ADD_EXECUTABLE( ${APP_EXECUTABLE} src/iteratorstest.cpp )
TARGET_LINK_LIBRARIES( ${APP_EXECUTABLE} ${LIB_NAME} )

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT ${APP_EXECUTABLE} )

include (CTest)
add_test(${APP_EXECUTABLE}_testIteratorFundamentals ${APP_EXECUTABLE} 1)
add_test(${APP_EXECUTABLE}_testIteratorIncrement ${APP_EXECUTABLE} 2)
add_test(${APP_EXECUTABLE}_testIteratorDecrement ${APP_EXECUTABLE} 3)
add_test(${APP_EXECUTABLE}_testIterationTricky ${APP_EXECUTABLE} 4)
add_test(${APP_EXECUTABLE}_testAlgorithms ${APP_EXECUTABLE} 5)
add_test(${APP_EXECUTABLE}_testLambda ${APP_EXECUTABLE} 6)

find_program(VALGRIND "valgrind")
if(VALGRIND)
	add_custom_target(valgrind
    COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --error-exitcode=1 $<TARGET_FILE:${APP_EXECUTABLE}>)
endif()
