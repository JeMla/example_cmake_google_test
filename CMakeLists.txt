# 2.8.12 is the minimum version required for google benchmark v1.4.1
cmake_minimum_required (VERSION 2.8.12)
project (learn_cmake)
set (prgm_VERSION_MAJOR 1)
set (prgm_VERSION_MINOR 0)

option(USE_GOOGLE_TEST
	"Compile google test and the related test cases"
	ON)
set(USE_GOOGLE_TEST_RELEASE "1.8.0" CACHE STRING
	"Select the release of google test to use")

option(USE_GOOGLE_BENCHMARK
	"Compile google benchmark and the related test cases"
	ON)
set(USE_GOOGLE_BENCHMARK_RELEASE "1.4.1" CACHE STRING
	"Select the release of google benchmark to use")

add_subdirectory(lib)
get_target_property(inc fact INCLUDE_DIRECTORIES)
include_directories(${inc})

add_definitions(-Wall -g)

enable_testing()
set(bench_output_dir ${CMAKE_CURRENT_BINARY_DIR}/benchResults)
file(MAKE_DIRECTORY ${bench_output_dir})

add_executable(prgm main/main.c)
set_target_properties(prgm PROPERTIES COMPILE_FLAGS -O3)
target_link_libraries(prgm fact)

add_executable(prgmDebug main/main.c)
set_target_properties(prgmDebug PROPERTIES COMPILE_FLAGS -g)
target_link_libraries(prgmDebug fact)

if (USE_GOOGLE_TEST)
add_executable(prgmUtests tests/factGoogleTests.cpp)
set_target_properties(prgmUtests PROPERTIES COMPILE_FLAGS -DDO_TESTS)
target_link_libraries(prgmUtests libgtest pthread fact)

include(ExternalProject)
ExternalProject_Add(
	googletest
	URL https://github.com/google/googletest/archive/release-${USE_GOOGLE_TEST_RELEASE}.zip
	URL_HASH SHA1=667f873ab7a4d246062565fad32fb6d8e203ee73
	PREFIX ${CMAKE_CURRENT_BINARY_DIR}/googletest-${USE_GOOGLE_TEST_RELEASE}
	INSTALL_COMMAND ""
	)
ExternalProject_Get_Property(googletest source_dir binary_dir)
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest googletest)
set_target_properties(libgtest PROPERTIES
	"IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
	"IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
	)
include_directories("${source_dir}/googletest/include")

add_test(UTs prgmUtests)
add_test(UT_twenty prgmUtests --gtest_filter=twenty)
endif()


if (USE_GOOGLE_BENCHMARK)
add_executable(prgmBenchs tests/factGoogleBenchmark.cpp)
set_target_properties(prgmBenchs PROPERTIES COMPILE_FLAGS -DDO_TESTS)
target_link_libraries(prgmBenchs libgbenchmark pthread rt fact)

ExternalProject_Add(
	googlebenchmark
	URL https://github.com/google/benchmark/archive/v${USE_GOOGLE_BENCHMARK_RELEASE}.zip
	PREFIX ${CMAKE_CURRENT_BINARY_DIR}/googlebenchmark-v${USE_GOOGLE_BENCHMARK_RELEASE}
	INSTALL_COMMAND ""
	CMAKE_ARGS -DBENCHMARK_ENABLE_GTEST_TESTS=OFF -DCMAKE_BUILD_TYPE=RELEASE
	)
ExternalProject_Get_Property(googlebenchmark source_dir binary_dir)
add_library(libgbenchmark IMPORTED STATIC GLOBAL)
add_dependencies(libgbenchmark googletest)
set_target_properties(libgbenchmark PROPERTIES
	"IMPORTED_LOCATION" "${binary_dir}/src/libbenchmark.a"
	"IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
	)
include_directories("${source_dir}/include")

add_test(BMs prgmBenchs --benchmark_format=csv --benchmark_out=./benchResults/Benchmarks.csv)
add_test(BM_twenty prgmBenchs --benchmark_filter=twenty --benchmark_format=csv --benchmark_out=./benchResults/twenty.csv)
endif()

