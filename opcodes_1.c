#include "mont.h"
/**
 * 
 */
void push(stack_t **stack, unsigned int nline)
{
	stack_t *new;

	if (stack == 0)
	{
		fprintf(stderr, "L%d stack not found\n", nline);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack(stack);
		exit(EXIT_FAILURE);
	}
	new->next = *stack;
	new->prev = NULL;
	new->n = arg.arg;
	if (*stack)
	{
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * 
 */
void pall(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * 
 */
void freeStack(stack_t **stack)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	while (stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * 
 */
void nop(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
}

/**
 * 
 */
int _isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
