#include "monty.h"
/**
 * 
 */
void pint (stack_t **stack, unsigned int nline)
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
 * 
 */
void pop (stack_t **stack, unsigned int nline)
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
 * 
 */
void swap(stack_t **stack, unsigned int nline)
{
	int temp;

	if (stack == NULL || *stack == NULL || !((*stack)->next))
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", nline);
			exit(EXIT_FAILURE);
		}
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
}

/**
 * 
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
 * 
 */
void pstr(stack_t **stack, unsigned int nline)
{
	int index = 0;
	char result[] = "";
	char c;
	stack_t *temp;

	temp = *stack;
	(void)nline;
	while (temp)
	{
		if (temp->n == 0)
		{
			break;
		}
		if (_isalpha(temp->n) == 0)
		{
			break;
		}
		c = temp->n;
		printf("%c\n", c);;
		result[index] += c;
		temp = temp->next;
		index++;
	}
	printf("\n");
}