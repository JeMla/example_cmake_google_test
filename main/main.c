#include <stdio.h>
#include <stdlib.h>

#include <fact.h>

int main (int argc, char **argv)
{
	int value;
	unsigned long long computed;

	if (argc != 2) {
		fprintf(stderr, "Missing arguments\n");

		return 1;
	}

	value = strtol(argv[1], NULL, 10);

	computed = fact(value);

	fprintf(stdout,
		"Fact %d is %llu\n",
		value, computed);

	return 0;
}

