#include "monty.h"
/**
 * opcomp - check command in dictionary
 * @opcode: the string name that is extracted by sscanf from getline
 * @stack: dptr to stack
 * @line_number: line number of monty file
 * Return: function pointer or null if no match
 */
void opcomp(stack_t **stack, unsigned int line_number, char *opcode)
{
	int index = 0;

	instruction_t opc[] = {
		{"push", stack_push}, {"pall", stack_pall},
		{"pint", stack_pint}, {"pop", stack_pop},
		{"swap", stack_swap}, {"add", add},
		{"nop", stack_nop}, {"sub", sub},
		{"div", divide}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}, {NULL, NULL}
	};

	while (opc[index].opcode != NULL)
	{
		if (strcmp(opcode, opc[index].opcode) == 0)
		{
			opc[index].f(stack, line_number);
			return;
		}
		index++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit_free(*stack);
	exit(EXIT_FAILURE);
}

/**
 * monty_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
