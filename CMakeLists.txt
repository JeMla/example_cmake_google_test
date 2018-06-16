# 2.8.12 is the minimum version required for google benchmark v1.4.1
cmake_minimum_required (VERSION 2.8.12)
project (learn_cmake)
set (fact_VERSION_MAJOR 1)
set (fact_VERSION_MINOR 0)

set(googletest_release 1.8.0)

# FIXME
# There is an issue for the compilation of google benchmark. It can not find
# the headers of google test, saying that GTEST_INCLUDE_DIR is not defined.
# Google test is not installed in a standard path, since it is compiled in
# this project. The definition and/or the export of GTEST_INCLUDE_DIR, in
# the CMakeLists or here or in the shell doesn't solve the problem.
# However, some (environment ?) variables are taken into account by google
# benchmark: setting GTEST_ROOT change the behaviour or google bechmark. Without
# this definition, google benchmark fails telling that GTEST_LIBRARY,
# GTEST_INCLUDE_DIR and GTEST_MAIN_LIBRARY could not be found. By defining
# GTEST_ROOT, only GTEST_INCLUDE_DIR still missing.
# The creation of symbolic links to /usr/include/ that points to the headers of
# google test solve the problem. It seems to be related to the installation
# directory.
# I'll try to use cmake to install gtest in a non standard directory
# instead of just pointing to the src or to the build directory.
option(USE_GOOGLE_BENCHMARK
	"Compile google benchmark and the related test cases"
	OFF)

if (USE_GOOGLE_BENCHMARK)
set(googlebenchmark_release v1.4.1)
endif()

enable_testing()
add_definitions(-Wall -g)

set(bench_output_dir benchResults)
file(MAKE_DIRECTORY ${bench_output_dir})

add_executable(fact main/main.c lib/fact.c)
set_target_properties(fact PROPERTIES COMPILE_FLAGS -O3)

add_executable(factDebug main/main.c lib/fact.c)
set_target_properties(factDebug PROPERTIES COMPILE_FLAGS -g)

add_executable(factUtests tests/factGoogleTests.cpp lib/fact.c)
set_target_properties(factUtests PROPERTIES COMPILE_FLAGS -DDO_TESTS)
target_link_libraries(factUtests libgtest pthread)

if (USE_GOOGLE_BENCHMARK)
add_executable(factBenchs lib/fact.c tests/factGoogleBenchmark.cpp)
set_target_properties(factBenchs PROPERTIES COMPILE_FLAGS -DDO_TESTS)
target_link_libraries(factBenchs benchmark pthread)
endif()

include(ExternalProject)
ExternalProject_Add(
	googletest
	URL https://github.com/google/googletest/archive/release-${googletest_release}.zip
	URL_HASH SHA1=667f873ab7a4d246062565fad32fb6d8e203ee73
	PREFIX ${CMAKE_CURRENT_BINARY_DIR}/googletest-${googletest_release}
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


if (USE_GOOGLE_BENCHMARK)
 ExternalProject_Add(
	googlebenchmark
	URL https://github.com/google/benchmark/archive/${googlebenchmark_release}.zip
	PREFIX ${CMAKE_CURRENT_BINARY_DIR}/googlebenchmark-${googlebenchmark_release}
	INSTALL_COMMAND ""
	)
endif()
add_test(UTs factUtests)
add_test(UT_twenty factUtests --gtest_filter=twenty)

if (USE_GOOGLE_BENCHMARK)
add_test(BMs factBenchs --benchmark_format=csv --benchmark_out=./benchResults/Benchmarks.csv)
add_test(BM_twenty factBenchs --benchmark_filter=twenty --benchmark_format=csv --benchmark_out=./benchResults/twenty.csv)
endif()

