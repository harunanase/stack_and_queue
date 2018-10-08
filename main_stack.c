#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
		Block *head = NULL;	/* initialize stack */
	
	
		while(1)
		{
				printf("\n\n\n==== Stack ====\n");
				printf("1) push\t2) pop\t3) print stack\t4) exit\nEnter option: ");


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
							push(msg, &head);
							break;
					case 2:
							pop(&head);
							break;
					case 3:
							print_stack(&head);
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


