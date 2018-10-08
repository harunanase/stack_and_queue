#ifndef __STACK_H__
#define __STACK_H__


#define MSG_SIZE 1024



struct block
{
		/* each block of the stack */
		char msg[MSG_SIZE];	/* messange storage */
		struct block *ptr;	/* pointer, points to next block */
};


typedef struct block Block; /* Alias, more readable */


void push(char data[MSG_SIZE], Block **head);	/* push a block into stack */
void pop(Block **head);	/* pop out a block from stack */
void print_stack(Block **head);	/* print the whole stack */

#endif
