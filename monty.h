#ifndef MONTY_H
#define MONTY_H

/* Standard libraries */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Data structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack-s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;

/* opcodes related prototypes */
void (*get_op_func(char *token1))(stack_t **stack, unsigned int line_number);
void push(stack_t **h, unsigned int line_number, const char *n);
void pop(stack_t **h, unsigned int line_number);
void pint(stack_t **h, unsigned int line_number);
void pall(stack_t **h, unsigned int line_number);
void swap(stack_t **h, unsigned int line_number);
void nop(stack_t **h, unsigned int line_number);
void pchar(stack_t **h, unsigned int line_number);
void pstr(stack_t **h, unsigned int line_number);
void rotl(stack_t **h, unsigned int line_number);
void rotr(stack_t **h, unsigned int line_number);

/* calculator prototypes */

void _add(stack_t **h, unsigned int line_number);
void _sub(stack_t **h, unsigned int line_number);
void _mul(stack_t **h, unsigned int line_number);
void _div(stack_t **h, unsigned int line_number);
void _mod(stack_t **h, unsigned int line_number);

/* doubly linked list related prototypes */

int add_end_node(stack_t **h, int n);
void delete_end_node(stack_t **h);
void free_dlist(stack_t **h);

/* extra prototypes */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void f_pop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);

#endif /* MONTY_H */
