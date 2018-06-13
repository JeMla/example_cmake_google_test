#include <stdio.h>
#include <stdlib.h>

long fact (int val);

int main (int argc, char **argv)
{
	int value;
	long computed;

	if (argc != 2) {
		fprintf(stderr, "Missing arguments\n");

		return 1;
	}

	value = strtol(argv[1], NULL, 10);

	computed = fact(value);

	fprintf(stdout,
		"Fact %d is %ld\n",
		value, computed);

	return 0;
}

