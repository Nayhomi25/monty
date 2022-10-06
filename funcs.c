#include "monty.h"

/**
 * get_builtin - Parses the instruction with the function.
 * @token: type pointer extern var char
 * @stack: type pointer node of data struct
 * @line_number: line of instructions
 * Return: Retunr the funtion
 */
int get_builtin(char *token, stack_t **stack, unsigned int line_number)
{
	instruction_t op_built[] = {
		{ "push", push },
		{ "pall", pall},
		{ "pop", pop },
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
		{ "pall", pall },
		{ "pint", pint },
		{ "swap", swap },
		{ "mul", mul },
		{ "div", div_m },
		{ "pchar", pchar },
		{ "mod", mod_m },
		{ "\n", nop },
		{ " ", nop },
		{ "\t", nop },
		{ "pstr", pstr_t },
		{ "rotl", rotrl },
		{ "rotr", rotr },
		{ NULL, NULL }
	};
	int i, flag = 0;
	char *argumentos = NULL;

	if (stack == NULL || token == NULL)
		return (0);
	argumentos = token;
	for (i = 0; op_built[i].opcode; i++)
	{
		if (strcmp(argumentos, op_built[i].opcode) == 0)
		{
			flag = 1;
			op_built[i].f(stack, line_number);
			break;
		}
	}
	if (flag == 0)
		stderr_unknown(token, line_number);
	return (0);
}

/**
 * create_node_stack - create a node stack.
 * @stack: A pointer to top and bottom stack.
 * Return: EXIT SUCCESS
 */
int create_node_stack(stack_t **stack)
{
	stack_t *p;

	p = malloc(sizeof(stack_t));
	if (p == NULL)
		stderr_malloc();
	p->n = STACK;
	p->prev = NULL;
	p->next = NULL;

	*stack = p;

	return (EXIT_SUCCESS);
}
/**
 * free_node_stack - Frees a stack_t stack.
 * @stack: A pointer to top and bottom stack.
 */
void free_node_stack(stack_t **stack)
{
	stack_t *temp_node = *stack;

	while (*stack)
	{
		temp_node = (*stack)->next;
		free(*stack);
		*stack = temp_node;
	}
}
/**
 * check_opcode - checks if STACK or QUEUE.
 * @stack: A pointer to top and bottom stack.
 * Return: The value of Stack or Queue
 */
int check_opcode(stack_t *stack)
{
	int ret_val = 2;

	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (ret_val);
}

/**
 * create_node_stackfirst - create a node stack.
 * @stack: A pointer to top and bottom stack.
 * @n: the value
 * Return: the node
 */
stack_t *create_node_stackfirst(stack_t **stack, int n)
{
	stack_t *newnode_stack;

	if (stack == NULL)
		return (NULL);
	newnode_stack = malloc(sizeof(stack_t));
	if (newnode_stack == NULL)
		stderr_malloc();
	newnode_stack->n = n;
	newnode_stack->next = *stack;
	newnode_stack->prev = NULL;
	*stack = newnode_stack;
	return (newnode_stack);
}
