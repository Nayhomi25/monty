#include "monty.h"


/**
 * pop - Add node to the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void pop(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (stack == NULL)
	{
		free_dlistint(*stack);
		pop_e(line_number); }
	if (*stack == NULL)
	{
		free_dlistint(*stack);
		pop_e(line_number); }
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		flag = 1;
	}
	temp2 = *stack;
	while (j < (i - 1))
	{
		temp2 = temp2->next;
		j++;
	}
	if (i == 0 && flag == 0)
	{

		free(*stack);
		*stack = NULL;
		return;
	}
	else
	{
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}

/**
 * swap - Print the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int i, j;

	if (*stack == NULL || stack == NULL)
		op_e(line_number, "swap");

	temp = (*stack)->next;
	if ((*stack)->next == NULL)
		op_e(line_number, "swap");
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	i = temp->n;
	j = temp->prev->n;
	temp->n = j;
	temp->prev->n = i;
}
/**
 * nop - does not do anything
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * free_dlistint - free a dlistint_t list.
 * @stack: pointer to the first element of the list
 * Return: no return
 */
void free_dlistint(stack_t *stack)
{
	stack_t *aux = NULL;
	stack_t *temp = NULL;

	temp = stack;
	while (temp != NULL)
	{
		aux = temp->next;
		free(temp);
		temp = aux;
	}
	stack = NULL;
}

/**
 * free_globalvars - free a dlistint_t list.
 *
 * Return: no return
 */
void free_globalvars(void)
{
	fclose(globalvar.fd);
	free(globalvar.line_buf);
}
