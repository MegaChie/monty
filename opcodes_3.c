#include "monty.h"
/**
 * rotl - check code.
 * @stack: struct double pointer
 * @nline: unsigned integer variable
 */
void rotl(stack_t **stack, unsigned int nline)
{
	stack_t *runner = *stack;
	int aux1 = 0;

	if (nline == NULL || stack == NULL || *stack == NULL ||
		(*stack)->next == NULL)
	{
		return;
	}
	aux1 = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}
	runner->n = aux1;
}


/**
 * rotlop - check code.
 * @stack: struct double pointer
 * @nline: unsigned integer variable
 */
void rotlop(stack_t **stack, unsigned int nline)
{
	stack_t *last, *temp;

	(void)nline;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	temp = *stack;
	last = temp;
	while (last->next)
	{
		last = last->next;
	}
	last->next = temp;
	temp->prev = last;
	temp->next->prev = NULL;
	*stack = temp->next;
	temp->next = NULL;
}

/**
 * rotrop - check code.
 * @stack: struct double pointer
 * @nline: unsigned integer variable
 */
void rotrop(stack_t **stack, unsigned int nline)
{
	stack_t *last, *temp;

	(void)nline;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	temp = *stack;
	last = temp;
	while (last->next)
	{
		last = last->next;
	}
	last->prev->next = NULL;
	last->prev = NULL;
	temp->prev = last;
	last->next = temp;
	*stack = last;
}

/**
 * qpush - check code.
 * @stack: struct double pointer
 * @nline: unsigned integer variable
 */
void qpush(stack_t **stack, unsigned int nline)
{
	stack_t *last, *new;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack(stack);
		exit(EXIT_FAILURE);
	}
	last = NULL;
	if (*stack)
	{
		last = *stack;
		while (last->next)
		{
			last = last->next;
		}
		last->next = new;
	}
	else
	{
		*stack = new;
	}
	new->prev = last;
	new->next = NULL;
	new->n = arg.arg;
}
