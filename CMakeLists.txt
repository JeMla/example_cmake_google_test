cmake_minimum_required (VERSION 2.6)
project (fact_codinggame)
set (fact_VERSION_MAJOR 1)
set (fact_VERSION_MINOR 0)

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
target_link_libraries(factUtests gtest pthread)

add_executable(factBenchs lib/fact.c tests/factGoogleBenchmark.cpp)
set_target_properties(factBenchs PROPERTIES COMPILE_FLAGS -DDO_TESTS)
target_link_libraries(factBenchs benchmark pthread)

add_test(UTs factUtests)
add_test(UT_twenty factUtests --gtest_filter=twenty)

add_test(BMs factBenchs --benchmark_format=csv --benchmark_out=./benchResults/Benchmarks.csv)
add_test(BM_twenty factBenchs --benchmark_filter=twenty --benchmark_format=csv --benchmark_out=./benchResults/twenty.csv)

