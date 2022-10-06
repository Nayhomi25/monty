#include "monty.h"

/**
 * pchar - Print char.
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void pchar(stack_t **stack, unsigned int line_number)
{

	stack_t *temp;

	if (*stack == NULL || stack == NULL)
	{
		pchar_e(line_number, "stack empty");
		return;
	}
	temp = (*stack);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp->n < 0 || temp->n > 127)
	{
		pchar_e(line_number, "value out of range");
	}
	printf("%c\n", temp->n);
}


/**
 * pstr_t - prints the string starting at the top of the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void pstr_t(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void)line_number;

	if (*stack == NULL || stack == NULL)
	{
		printf("\n");
		free_globalvars();
		exit(0);
	}
	temp = *stack;
	if (temp->next == NULL && line_number == 2 && (temp->n < 0 || temp->n >= 127))
	{
		printf("\n");
		free_dlistint(*stack);
		free_globalvars();
		exit(0);
	}
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		if (temp->n > 0 && temp->n < 127)
		{
			printf("%c", temp->n);
			temp = temp->prev;
		}
		else
			temp = temp->prev;
		if (temp->n <= 0 || temp->n >= 127)
		{
			printf("\n");
			return;
		}
	}
	printf("%c\n", temp->n);
}
/**
 * rotrl - rotate to left
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void rotrl(stack_t **stack, unsigned int line_number)
{

	stack_t *temp2 = NULL;
	stack_t *temp = NULL;
	(void)line_number;

	if (*stack == NULL || ((*stack)->next == NULL))
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp2 = temp->prev;
	temp2->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
/**
 * rotr - rotate to left
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp2 = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;
	temp2 = *stack;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = *stack;
	(*stack)->prev = temp2;
	temp2 = (*stack)->next;
	(*stack)->next = NULL;
	*stack = temp2;
	(*stack)->prev = NULL;
}
