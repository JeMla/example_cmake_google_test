#include "gtest/gtest.h"

extern "C" unsigned long long fact (int val);

unsigned long long testVect [] = {
	1,
	1,
	2,
	6,
	24,
	120,
	720,
	5040,
	40320,
	362880,
	3628800,
	39916800,
	479001600,
	6227020800,
	87178291200,
	1307674368000,
	20922789888000,
	355687428096000,
	6402373705728000,
	121645100408832000,
	2432902008176640000
};

#define DECLARE_UTEST(name, testCase, expRes) \
	TEST (fact, test_##name) { \
		EXPECT_EQ(expRes, fact(testCase)); \
	}

DECLARE_UTEST(zero, 0, testVect[0]);
DECLARE_UTEST(one, 1, testVect[1]);
DECLARE_UTEST(two, 2, testVect[2]);
DECLARE_UTEST(three, 3, testVect[3]);
DECLARE_UTEST(four, 4, testVect[4]);
DECLARE_UTEST(five, 5, testVect[5]);
DECLARE_UTEST(six, 6, testVect[6]);
DECLARE_UTEST(seven, 7, testVect[7]);
DECLARE_UTEST(eight, 8, testVect[8]);
DECLARE_UTEST(nine, 9, testVect[9]);
DECLARE_UTEST(ten, 10, testVect[10]);
DECLARE_UTEST(eleven, 11, testVect[11]);
DECLARE_UTEST(twelve, 12, testVect[12]);
DECLARE_UTEST(thirteen, 13, testVect[13]);
DECLARE_UTEST(fourteen, 14, testVect[14]);
DECLARE_UTEST(fifteen, 15, testVect[15]);
DECLARE_UTEST(sixteen, 16, testVect[16]);
DECLARE_UTEST(seventeen, 17, testVect[17]);
DECLARE_UTEST(eighteen, 18, testVect[18]);
DECLARE_UTEST(nineteen, 19, testVect[19]);
DECLARE_UTEST(twenty, 20, testVect[20]);

int main (int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

