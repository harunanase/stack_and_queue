#ifndef __QUEUE_H__
#define __QUEUE_H__


#define MSG_SIZE 1024



struct block
{
		/* each block of the queue */
		char msg[MSG_SIZE];	/* messange storage */
		struct block *ptr;	/* pointer, points to next block */
};


typedef struct block Block; /* Alias, more readable */


void push(char data[MSG_SIZE], Block **head, Block **tail);	/* push a block into queue */
void pop(Block **head, Block **tail);	/* pop out a block from queue */
void print_queue(Block **head);	/* print the whole queue */

#endif
