#include "monty.h"
arg_t arg = {0, 0};

/**
 * commentCheck - check code.
 * @line: struct variable
 * Return: true or false
 */
bool commentCheck(line_t line)
{
	if (!line.content[0])
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
 * argumentCheck - check code.
 * @token: char pointer
 * Return: false ort true
 */
bool argumentCheck(char *token)
{
	unsigned int count;

	if (!token)
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
 * pushCheck - check code.
 * @line: struct variable
 * @meta: struct pointer
 * @opcode: char pointer
 */
void pushCheck(line_t line, meta_t *meta, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) && !argumentCheck(line.content[1]))
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
		arg.arg = atoi(line.content[1]);
	}
}
