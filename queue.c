#include "queue.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void push(char data[MSG_SIZE], Block **head, Block **tail)
{
		/* push a block into the top of queue
		 * data: the messange of the block, max size depends on MSG_SIZE 
		 * head: pointer, points to the head of queue
		 * tail: pointer, points to the tail of queue */
		
		
		
		Block *nblock = malloc(sizeof(Block));	/* allocate new block */
		strncpy(nblock->msg, data, MSG_SIZE);	/* copy data to new block */
		nblock->ptr = NULL;	/* the last block of queue, points to "nothing". */


		/* test boundary condition */
		if( (*tail) == NULL )
		{
				/* empty queue */
				(*head) = nblock;
				(*tail) = nblock;

		}
		else
		{
				/* normal condition */
				(*tail)->ptr = nblock;	/* let the previous block points to the new block */
				(*tail) = (*tail)->ptr;	/* update tail */				
		}
}

void pop(Block **head, Block **tail)
{
		/* pop out a block from the tail of queue
		 * head: pointer, points to the head of queue
		 * tail: pointer, points to the tail of queue */


		/* test boudary condition, whether the queue is empty */
		if( (*head) == NULL )
		{
				/* empty queue, raise error */
				printf("ERROR: empty queue\n");	
		}	
		else
		{
				/* normal condition */
				Block *temp = (*head);
				(*head) = (*head)->ptr;
				printf("The poped block messange is: %s\n", temp->msg);
				free(temp);
		}

}

void print_queue(Block **head)
{
		/* print the whole queue */

		if((*head) == NULL)
		{
				/* queue empty, exit. */
				printf("The queue is empty.\n");
				return ;	
		}
		else
		{
				/* not empty, iteratively print it */
				printf("The queue: \n");
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
