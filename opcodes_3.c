#include "monty.h"
/**
 * 
 */
void rotl(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	int holdThis, holdThisAgain;
	(void)nline;

	if (stack == NULL || *stack == NULL)
	{
		nop(stack, nline);
	}
	holdThis = (*stack)->n;
	temp = *stack;
	while (temp)
	{
		if (temp->next == NULL)
		{
			break;
		}
		temp = temp->next;
	}
	holdThisAgain = temp->n;
	(*stack)->n = holdThisAgain;
	temp->n = holdThis;
}

/**
 * 
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
 * 
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
 * 
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
