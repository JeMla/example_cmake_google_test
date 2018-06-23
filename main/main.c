#include <stdio.h>
#include <stdlib.h>

#include <factConfig.h>
#include <fact.h>

int main (int argc, char **argv)
{
	int value;
	unsigned long long computed;

    fprintf(stdout, "PROJECT '%s'\n", PROJECT);
    fprintf(stdout, "PROJECT_VERSION '%s'\n", PROJECT_VERSION);
    fprintf(stdout, "PROJECT_VERSION_MAJOR '%s'\n", PROJECT_VERSION_MAJOR);
    fprintf(stdout, "PROJECT_VERSION_MINOR '%s'\n", PROJECT_VERSION_MINOR);
    fprintf(stdout, "PROJECT_VERSION_PATCH '%s'\n", PROJECT_VERSION_PATCH);
    fprintf(stdout, "PROJECT_VERSION_TWEAK '%s'\n", PROJECT_VERSION_TWEAK);

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

