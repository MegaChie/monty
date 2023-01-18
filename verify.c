#include "monty.h"
arg_t arg = {0, 0};

/**
 * 
 */
bool commentCheck(line_t line)
{
	if (line.content[0] == NULL)
	{
		free(line.content);
		return (true);
	}
	if (line.content[0][0] == '#')
	{
		free(line.content);
		return (true);
	}
	return (false);
}

/**
 * 
 */
bool argumentCheck(char *token)
{
	unsigned int count;

	if (token == NULL)
	{
		return (false);
	}
	for (count = 0; token[count]; count++)
	{
		if (token[0] == '-')
		{
			continue;
		}
		if (token[count] < '0' || token[count] > '9')
		{
			return (false);
		}
	}
	return (true);
}

/**
 * 
 */
void pushCheck(line_t line, meta_t *meta, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) && argumentCheck(line.content[1]))
	{
		free(line.content);
		fprintf(stderr, "L%d: usage: push integer\n", line.number);
		free(meta->buffer);
		freeStack(&(meta->stack));
		fclose(meta->file);
		free(meta);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
	{
		arg.arg = atio(line.content[1]);
	}
}
