#include "monty.h"
/**
 * 
 */
void (*get_op_func(line_t line, meta_t *meta))(stack_t **, unsigned int)
{
	unsigned int count = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", addop},
		{"sub", subop},
		{"div", divop},
		{"mul", mulop},
		{"mod", modop},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotlop},
		{"rotr", rotrop},
		{"stack", addst},
		{"queue", addqu},
		{NULL, NULL}
	};

	if (commentCheck(line))
	{
		return (nop);
	}
	while (ops[count].opcode)
	{
		if (strcmp(ops[count].opcode, line.content[0]) == 0)
		{
			pushCheck(line, meta, ops[count].opcode);
			if (arg.flag == 1 &&
			strcmp(ops[count].opcode, "push") == 0)
			{
				if (line.content)
					free(line.content);
				return (qpush);
			}
			free(line.content);
			return (ops[count].f);
		}
		count++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line.number,
	line.content[0]);
	free(line.content);
	free(meta->buffer);
	freeStack(&(meta->stack));
	fclose(meta->file);
	free(meta);
	exit(EXIT_FAILURE);
}
