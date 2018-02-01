cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(DataStructures)

set (CMAKE_CXX_STANDARD 17)

#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

SET (Boost_DETAILED_FAILURE_MSG ON)
SET (BOOST_DEBUG ON)

IF(WIN32)
    SET(BOOST_ROOT "C:/boost_1_66_0")
	SET(BOOST_LIBRARYDIR "C:/boost_1_66_0/lib64-msvc-14.1")
ENDIF()

find_package(Boost
  1.66.0                 # Minimum or EXACT version e.g. 1.36.0
  REQUIRED               # Fail with error if Boost is not found
						 # Boost libraries by their canonical name  
  COMPONENTS unit_test_framework                       
                         # e.g. "date_time" for "libboost_date_time"
  )                      

MESSAGE (${Boost_FOUND})
MESSAGE (${Boost_INCLUDE_DIRS})
MESSAGE (${Boost_LIBRARY_DIRS})

foreach(loop_var ${Boost_LIBRARIES})
  MESSAGE (${loop_var})
endforeach(loop_var)

foreach(loop_var )
  MESSAGE (${Boost_LIB_DIAGNOSTIC_DEFINITIONS})
endforeach(loop_var)

get_filename_component(UTF_BASE_NAME ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY_DEBUG} NAME_WE)
get_filename_component(UTF_PATH ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY_DEBUG} PATH)
MESSAGE(${UTF_BASE_NAME})
MESSAGE(${UTF_PATH})
MESSAGE(${UTF_PATH}/${UTF_BASE_NAME}.dll)

IF(Boost_FOUND)
    enable_testing()

	include_directories(SYSTEM ${Boost_INCLUDE_DIRS} ${DataStructures_SOURCE_DIR})
	link_directories(${Boost_LIBRARY_DIRS})

	add_executable(TestDriven 
	                           test/UnitTest.cpp
							   test/testDriven.cpp
							   )
    target_link_libraries(TestDriven ${Boost_LIBRARIES})

	add_executable(DataStructuresUnitTest 
	                           test/UnitTest.cpp
							   test/ADTTest.cpp
							   test/AnotherTest.cpp
							   test/CollectionTest.cpp
							   test/DequeTest.cpp
							   test/StackTest.cpp
							   )
	target_link_libraries(DataStructuresUnitTest ${Boost_LIBRARIES})

	add_executable(sortingTest 
	                           test/UnitTest.cpp
	                           test/sortingTest
							   )
	target_link_libraries(sortingTest ${Boost_LIBRARIES})

	SET(CTEST_OUTPUT_ON_FAILURE TRUE)

	add_test(build_test "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR})
	add_test(TestDriven TestDriven)
	add_test(DataStructuresUnitTest DataStructuresUnitTest)
	add_test(sortingTest sortingTest)
ENDIF()

add_executable(HelloWorld HelloWorld.cpp)