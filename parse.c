#include "monty.h"
/**
 * 
 */
void parseLine(line_t *line, char *buffer)
{
	unsigned int count;
	char *token = NULL;

	line->content = malloc(sizeof(char *) * 3);
	if (!line->content)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " '\n'");
	for (count = 0; token && count < 2; count++)
	{
		line->content[count] = token;
		token = strtok(NULL, " \n");
	}
	line->content[count] = NULL;
}

/**
 * 
 */
void parseFile(FILE *file)
{
	size_t size = 0;
	meta_t *meta = NULL;
	line_t line;

	meta = malloc(sizeof(meta_t));
	if (meta == 0)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	line.number = 0;
	line.content = NULL;
	meta->file = file;
	meta->stack = NULL;
	meta->buffer = NULL;
	while (getline(&(meta->buffer), &size, meta->file) != -1)
	{
		line.number++;
		parseLine(&line, meta->buffer);
		if (line.content)
		{
			get_op_func(line, meta)(&(meta->stack), line.number);
		}
	}
	free(meta->buffer);
	freeStack(&(meta->stack));
	fclose(meta->file);
	free(meta);
}
