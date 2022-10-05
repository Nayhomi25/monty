#include "monty.h"
/**
 * stack_pop - removes top item from stack
 * @stack: stack
 * @line_number: monty file line number
 * Return: void
 */
void stack_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	if (tmp->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
}
/**
 * stack_nop - do nothing
 * @stack: unused
 * @line_number: unused
 * Return: void
 */
void stack_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * stack_swap - swaps data from top two nodes in stack
 * @stack: stack
 * @line_number: monty file line number
 * Return: void
 */
void stack_swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit_free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
