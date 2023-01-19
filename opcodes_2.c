#include "monty.h"
/**
 * pint - check code.
 * @stack: struct double pointer
 * @nline: unsigned integer variable
 */
void pint(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp)
	{
		if (temp->prev == NULL)
		{
			break;
		}
		temp = temp->prev;
	}
	printf("%d\n", temp->n);
}

/**
 * pop - check code.
 * @stack: struct double pointer
 * @nline: unsigned integer variable
 */
void pop(stack_t **stack, unsigned int nline)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", nline);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * swap - check code.
 * @stack: struct double pointer
 * @nline: unsigned integer variable
 */
void swap(stack_t **stack, unsigned int nline)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * pchar - check code.
 * @stack: struct double pointer
 * @nline: unsigned integer variable
 */
void pchar(stack_t **stack, unsigned int nline)
{
	char c;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp)
	{
		if (temp->prev == NULL)
		{
			break;
		}
		temp = temp->prev;
	}
	c = temp->n;
	if (_isalpha(temp->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", nline);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}

/**
 * pstr - check code.
 * @stack: struct double pointer
 * @nline: unsigned integer variable
 */
void pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
