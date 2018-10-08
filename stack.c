#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void push(char data[MSG_SIZE], Block **head)
{
		/* push a block into the top of stack
		 * data: the messange of the block, max size depends on MSG_SIZE 
		 * head: pointer, points to the head of stack */

		Block *nblock = malloc(sizeof(Block));	/* allocate new block */
		strncpy(nblock->msg, data, MSG_SIZE);	/* copy data to new block */
		nblock->ptr = (*head);	/* points to the next block (This block used to be the top of stack.) */
		(*head) = nblock;	/* let head points to the new block */
}

void pop(Block **head)
{
		/* pop out a block from the top of stack
		 * head: pointer, points to the head of stack */
		
		if((*head) != NULL)
		{
				/* normal condition, the stack isnot EMPTY */
				
				Block *temp = (*head);	/* temp pointer, points to the poped block */
				(*head) = (*head)->ptr;	/* the head of the stack moves to the next block */
				printf("The poped block messange is: %s\n", temp->msg);
				free(temp);	/* free the poped block */
		}
		else
		{
				/* boundary condition, the stack is empty */

				printf("ERROR: the stack is empty.\n");
		}
}

void print_stack(Block **head)
{
		/* print the whole stack */

		if((*head) == NULL)
		{
				/* stack empty, exit. */
				printf("The stack is empty.\n");
				return ;	
		}
		else
		{
				/* not empty, iteratively print it */
				printf("The stack: \n");
				for(Block *i=(*head); i!=NULL; i = i->ptr)
				{
						printf("%s", i->msg);
						if(i->ptr != NULL)
						{
								printf(" -> ");
						}
						else
						{
								printf("\n");
						}
				}
		}
}
