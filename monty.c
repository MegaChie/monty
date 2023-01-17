#include "monty.h"
/**
 * 
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
	if !file
	{
		fprintf(stderr, "Error: Can't open file %s\n", );
		exit(EXIT_FAILURE);
	}
	parsefile(file);
	return (EXIT_SUCCESS);
}
