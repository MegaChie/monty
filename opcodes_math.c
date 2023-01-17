#include "monty.h"
/**
 * 
 */
void addop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack)->next->n += (stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * 
 */
void subop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->n`;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * 
 */
void divop(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", nline);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * 
 */
