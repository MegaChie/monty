#include "monty.h"
/**
 * main - start here
 * @argc: argument count (integer variable)
 * @argv: argument vector (char pointer)
 * Retuen: exit status
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	parseFile(file);
	return (EXIT_SUCCESS);
}
