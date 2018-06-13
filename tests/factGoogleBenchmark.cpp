#include <benchmark/benchmark.h>

extern "C" long fact (int val);

#define DECLARE_BENCHMARK(name, testCase) \
	static void BM_##name(benchmark::State& state) { \
		fact(testCase); \
	}

DECLARE_BENCHMARK(one, 0);
DECLARE_BENCHMARK(two, 1);
DECLARE_BENCHMARK(three, 2);
DECLARE_BENCHMARK(four, 3);
DECLARE_BENCHMARK(five, 4);
DECLARE_BENCHMARK(six, 5);
DECLARE_BENCHMARK(seven, 6);
DECLARE_BENCHMARK(eight, 7);
DECLARE_BENCHMARK(nine, 8);
DECLARE_BENCHMARK(ten, 9);
DECLARE_BENCHMARK(eleven, 10);
DECLARE_BENCHMARK(twelve, 11);
DECLARE_BENCHMARK(thirteen, 12);
DECLARE_BENCHMARK(fourteen, 13);
DECLARE_BENCHMARK(fifteen, 14);
DECLARE_BENCHMARK(sixteen, 15);
DECLARE_BENCHMARK(seventeen, 16);
DECLARE_BENCHMARK(eighteen, 17);
DECLARE_BENCHMARK(nineteen, 18);
DECLARE_BENCHMARK(twenty, 19);


BENCHMARK(BM_one);
BENCHMARK(BM_two);
BENCHMARK(BM_three);
BENCHMARK(BM_four);
BENCHMARK(BM_five);
BENCHMARK(BM_six);
BENCHMARK(BM_seven);
BENCHMARK(BM_eight);
BENCHMARK(BM_nine);
BENCHMARK(BM_ten);
BENCHMARK(BM_eleven);
BENCHMARK(BM_twelve);
BENCHMARK(BM_thirteen);
BENCHMARK(BM_fourteen);
BENCHMARK(BM_fifteen);
BENCHMARK(BM_sixteen);
BENCHMARK(BM_seventeen);
BENCHMARK(BM_eighteen);
BENCHMARK(BM_nineteen);
BENCHMARK(BM_twenty);

BENCHMARK_MAIN();

