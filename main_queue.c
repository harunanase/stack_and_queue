#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
		Block *head = NULL;	/* initialize queue */
		Block *tail = NULL;
	
		while(1)
		{
				printf("\n\n\n==== Queue ====\n");
				printf("1) push\t2) pop\t3) print queue\t4) exit\nEnter option: ");


				char msg[MSG_SIZE];

				/* get option from stdin */
				int option = 0;
				char enterFilter;
				scanf("%d%c", &option, &enterFilter);
				
				switch(option)
				{
					case 1:	
							/* push, get line from user  */
							printf("Enter some messange: ");
							scanf("%s", msg);
							push(msg, &head, &tail);
							break;
					case 2:
							pop(&head, &tail);
							break;
					case 3:
							print_queue(&head);
							break;
					case 4:
							exit(0);
							break;
					default:
							printf("ERROR: wrong option, please enter again.\n");
				}
		}
		return 0;
}


